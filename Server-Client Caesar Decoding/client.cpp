#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>

using namespace std;

int main() {

    int client;
    int portNum = 6013;  //The port number is same for both client and server
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

    //ESTABLISHING SOCKET CONNECTION
    if (client < 0) {
        cout << endl <<"Error establishing socket..." << endl;
        exit(1);
    }

    cout <<endl<< "> Client has been created!" << endl;


    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    //CONNECTING THE SOCKET
	if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "> Connection to the server port number: " << portNum << endl;

    
    cout << "> Connected with the server!"<< endl << endl;

 
    cout << "Send encrypted data: ";
    cin >> buffer;
    send(client, buffer, bufsize, 0);

    cout << "Received decrypted data: ";
    recv(client, buffer, bufsize, 0);
    cout << buffer << endl;
    
    //CLOSE CALL
    close(client);
    return 0;
}
