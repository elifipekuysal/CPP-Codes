#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void SezarDecryption(char encryptedData[]) {
	char ch;  //Keep one character from the encryptedData string each time
    int key= 3;  //key number which is used to decrypt one character

    for (int i = 0; encryptedData[i] != '\0'; ++i) {  //Control if it is the end of the array or not
        ch = encryptedData[i];  //ch will keep one character of the array sequentally in each loop 

        if (ch >= 'a' && ch <= 'z') {  //Compare ASCII values to be sure if ch is between 'a' and 'z'
            ch = ch - key;  //Decrypt ch with the key and assign new character to itself

            if (ch < 'a') {  //If decrypted character's ASCII value becomes lower than 'a's 
                ch = ch + 'z' - 'a' + 1;
            }
            encryptedData[i] = ch;  //Change encrypted character with the decrypted one
        }
		else if (ch >= 'A' && ch <= 'Z') {  //Compare ASCII values to be sure if ch is between 'A' and 'Z'
            ch = ch - key;

            if (ch > 'a') {  //If decrypted character's ASCII value becomes greater than 'a's
                ch = ch + 'Z' - 'A' + 1;
            }
            encryptedData[i] = ch;  //Change encrypted character with the decrypted one
        }
    }
    cout << "Decrypted data is: "<< encryptedData<<endl;
}

int main() {
    
    int server, client;
    int portNum = 6013;  //The port number is same for both client and server
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;
    socklen_t size;

    //ESTABLISHING SOCKET CONNECTION
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) {
        cout << endl <<"Error establishing socket..." << endl;
        exit(1);
    }

    cout << endl << "> Socket server has been created..." << endl;


    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    //BINDING THE SOCKET
    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0) {
        cout << "> Error binding connection!" << endl;
        return -1;
    }

    size = sizeof(server_addr);

    //LISTENING CALL
    listen(client, 1);

    //ACCEPTING CLIENTS
    server = accept(client,(struct sockaddr *)&server_addr,&size);

    //Check if connection is valid or not
    if (server < 0) 
        cout << "> Error! Server couldn't opened!" << endl;

    while (server > 0) {
        cout << "> Connected with the client!" << endl << endl;

        cout << "Received encrypted data is: ";
        recv(server, buffer, bufsize, 0);
        cout << buffer <<endl;
        SezarDecryption(buffer);
        
        cout << "Server is sending the decrypted data: "<<buffer<<endl;
        send(server, buffer, bufsize, 0);
        
        //CLOSE CALL
        close(server);
        exit(1);
    }

    close(client);
    return 0;
}
