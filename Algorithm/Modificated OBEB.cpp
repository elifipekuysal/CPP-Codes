#include<iostream>
#include <algorithm>
using namespace std;

int modificatedOBEB(int x, int y) {
	int counter = 1;

	while (x % 2 == 0 && y % 2 == 0) {
		x /= 2;
		y /= 2;
		counter *= 2;
	}
	while (x % 2 == 0){
		x /= 2;
	}
	while (x > 0 && y > 0){
		if (y > x) {
			swap(x, y);
		}
		while (x >= y) {
			y = x - y;
			x = x - y;
		}
	}
	return (y*counter);
}

int main() {
	int a, b;
	int result;

	cout << "Enter two positive values: ";
	cin >> a >> b;
	while(a<0 || b<0) {
		cout << "Please enter positive integers: ";
		cin >> a >> b;
	} 

	result = modificatedOBEB(a, b);
	cout << "OBEB(a,b)= " << result;
	
	return 1;
}
