//Homework4 - Question5
#include<iostream>
#include <cmath>
using namespace std; 

//f(x)  ->  Has just one root in [a,b] interval.

double f(double x) {
	int a1=1;
	int a2=1;
	int a3=(-2);
	return a1 * x * x + a2 * x + a3; 
}

bool isFoundError(double a, double b,double E) {		
	if(fabs((a-b)/2) <= E)  //E >= |(a-b)/2|; E error value
		return true;
	else
		return false;
}

void inInterval(double a, double b) {
	double c=(a+b)/2;  //In worst case root must be middle point of the interval (with error value (b-a)/2)
	double E=0.01;  //Error value
	 
	if(f(c)==0) 
		cout<<"Root of the function is: "<<c<<endl;
	else{
		while(1){
			c= (a+b)/2;
				
			if(isFoundError(a,b,E) == true) {  //If (b-a)/2 <= E then c must be the root with error value 0.01
				cout<<"Root of the function with error value 0.01 is: "<<c<<endl;
				break;
			}
	
			else {
				if(f(a)*f(c)<0) //If root is in [a,c]
					b=c;
				else if(f(c)*f(b)<0) //If root is in [c,b]
					a=c;	
			}
		}
	}
}

void findInterval(double a, double b) {	
	if(a<b)    //In [a,b] interval; it is necessary that a<b.
		cout<<"["<<a<<","<<b<<"]"<<endl;
	else {   //If b<a then swap a and b to ensure that a<b
		a=a+b;
		b=a-b;
		a=a-b;
		cout<<"["<<a<<","<<b<<"]"<<endl;
	}
	inInterval(a,b);
}

int main() {
	double a=-1, b=4;  //[a, b] interval

	findInterval(a,b);
	
	return 1;
}
