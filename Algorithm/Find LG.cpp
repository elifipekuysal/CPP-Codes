#include<iostream>
using namespace std;

int lgFindingFunction(int n) {
	int power = 0;    //Power of 2 
	
	while(n%2 == 0) {    //If n can be divided by two, then try to find if it is a power of 2.
		n /= 2;
		power++;    //When dividing with 2, increase power by 1.
	}
	if(n == 1) {    //In this point if n equals to 1, n must be a power of 2. (In the starting point if n==1 (== 2^0) power will be 0)
		return power;    //If n is a power of 2, then the result must be power's value. (return power) 
	} 
	while (n!=1) {    //If n isn't a power of 2, then keep going to find the value which is the smallest value greater than n.
		n /= 2;    //Keep dividing n with 2 to find the power of 2 which is biggest value smaller than n.
		power++;    //When dividing with 2, increase power by 1.
	}
	return (power+1);    //As a result, we find the following: lg(2^power) < lgn < lg(2^(power+1)). So, the smallest value greater than lgn must be (power+1).
}                                                                  // power < n < power+1

int main() {
	int n;
	do {
		cout<<"Please enter a positive integer: ";
		cin>>n;
	}while(n<=0);    //If input equals or smaller than 0, then ask for a positive integer again.
	
	cout<<"Result of the lg"<<n<<" is: "<<lgFindingFunction(n);
	return 1;
}
