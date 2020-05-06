#include<iostream>
using namespace std;

void isOpen(int N) {
	int Cup[N];    //Create an array that carries all of the cup numbers.
	
	for(int i=0; i < N; i++){
		Cup[i] = i+1;    //Assign numbers for N cups (1,2,...,N).
	}
	
	cout<< "Cup numbers of open cups are: "<<endl;
	for(int operation=0; operation < N; operation++) {    //Do N operation in total.
		int opTime=0;    //Total operation time for a cup.
		for(int cupNum = 1; cupNum < (N+1); cupNum++){    
			if(Cup[operation] % cupNum == 0) {    //Check the number of the cups one by one, for calculating if cup's number can be divided by them. 
				opTime++;    //Increase opTime by 1, if cup's number can be divided by some of the all cups numbers.
			}
		}
		if(opTime % 2 == 1) {//If opTime of a cup's number cannot be divided fully with 2, then it must be open. (In starting point, all of the cups are closed.) 
			cout<<Cup[operation]<<" ";  //2.n -> closed & 2.n+1 -> open
		}
	}
}

int main() {
	int N;    //Number of cups
	
	do{
		cout<<"Please enter a positive integer for the number of cups: ";
		cin>>N;
	}while(N < 0);
	
	isOpen(N);    //Call isOpen function.
	return 1;
}
