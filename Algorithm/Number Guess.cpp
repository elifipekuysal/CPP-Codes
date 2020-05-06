//Homework5 - Question1
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std; 

void findNumber(int end) {
	int start=1;
	int mid;
	string selection;
	
	cout<<"I try to guess the number, but please give me a little hint about it :)."<<endl;

	while(start<=end) {
		mid= (start+end)/2;
		
		if(start==end) {
			cout<<"Guessed number is: "<<mid<<"."<<endl;
			break;
		}

		cout<<"          x <= "<<mid<<" ?"<<endl;
		cout<<"If it is true type \'yes\', if not type \'no\': ";
		cin>>selection;
		transform(selection.begin(), selection.end(), selection.begin(), ::tolower);
		
		if(selection == "yes") {
			end= mid;
		}
		else if(selection == "no") {
			start= mid+1;
		}	
	}
}

int main() {
	int n;

	cout<<"Please enter a value for n in [1,n] interval: ";
	cin>>n;

	cout<<"Please think of a number in interval [1,"<<n<<"]."<<endl;

	findNumber(n);
	return 1;
}
