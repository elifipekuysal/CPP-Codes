//Homework5 - Question2
#include <iostream>
using namespace std;
 
int main(){
	int index;
	int counter=1;
	int find;
	
	cout<<"Please enter a value n for matrix[n][n]: ";
	cin>>index;
	int matrix[index][index];
 	int r=index-1;
	int c=0;

	for(int i=0; i<index; i++) {
		for(int j=0; j<index; j++) {
			matrix[i][j] = counter;
			counter++;
		}
	}
	cout<<"Please enter a number that you want to find in [1,"<<index*index<<"] interval: ";
	cin>>find;
	
	while(1){	
		if(find == matrix[r][c]) {
			cout<<"Number found on row: "<<r+1<<" and column: "<<c+1<<"."<<endl;
			break;
		}
		else if(find > matrix[r][c]) {
			c= c+1;
		}
		else if(find < matrix[r][c]) {
			r= r-1;
		}
	}
	
	return 1;
}
