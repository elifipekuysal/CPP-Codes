#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[]) {
	int fd[2], fd2[2];  //Array's for reading and writing operations between parent and child processes
	long int number;  //Number to be reversed
	long int reverseNum= 0, remainder= 0;  //Variables used for reversing number

	//Create pipe descriptors
	pipe(fd);  //Parent to child
	pipe(fd2);  //Child to parent

	//fork() returns 0 for child process, child-pid for parent process.
	if (fork() != 0) {  //Parent process
		cout<<"Please enter a number: ";
		cin>>number;  //Enter the number to be reversed
		
		close(fd[0]);  //Close read when writing
		write(fd[1], &number, sizeof(number));  //Write number for sending it to child process via 1st pipe
		cout<<"Parent("<<getpid()<<") send number: "<<number<<endl;
		close(fd[1]);  //Close write 
		
		close(fd2[1]);  //Close write when reading
		read(fd2[0], &reverseNum, sizeof(reverseNum));  //Read reversed number from child process via 2nd pipe
		close(fd2[0]);  //Close read
		
		cout<<"Reversed number is: "<<reverseNum<<endl;  //Print reversed number in parent process
	} 
	else {
		close(fd[1]);  //Close write when reading
		read(fd[0], &number, sizeof(number));  //Read the number from parent process via 1st pipe
		cout<<"Child("<<getpid()<<") received number: "<<number<<endl;
		close(fd[0]);  //Close read
		
			//Reversing operations
			while(number!=0) {
				remainder=number%10;
				reverseNum=reverseNum*10+remainder;
				number/=10;
			}	

		close(fd2[0]);  //Close read when writing
		write(fd2[1], &reverseNum, sizeof(reverseNum));  //Write number for sending it to parent process via 2nd pipe
		close(fd2[1]);  //Close write 
	}
	
	return 0;
}
