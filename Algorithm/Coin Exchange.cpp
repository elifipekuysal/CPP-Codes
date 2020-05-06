#include <iostream>

using namespace std;

//infinity: actually a very large number
#define INF 999

void coinChange(int d[], int C[], int S[], int N, int A) {
	int i, p, min, coin;
	
	//when amount is 0
	//then min coin required is 0
	C[0] = 0;
	S[0] = 0;
	
	for(p = 1; p <= A; p++) {
		min = INF;
		for(i = 1; i <= N; i++) {
			if(d[i] <= p) {
				if(1 + C[p - d[i]] < min) {
					min = 1 + C[p - d[i]];
					coin = i;
				}
			}
		}
		C[p] = min;
		S[p] = coin;
	}
}

void coinSet(int d[], int S[], int A) {
	while(A > 0) {
		cout<< d[S[A]]<<" ";
		A = A - d[S[A]];
	}
	cout<<endl;
}

int main(void) {

	int N;
	cin>>N;
	N+=1; 
	//denomination d of the coins
	//we will start from index 1
	//so, index 0 is set to 0
	int d[N];
	for(int i=1; i<N; i++) {
		cin>>d[i];
	}
	
	int A;
	cin>>A;
	
	//Minimum number of coins required to make change
	int C[A+1];
	
	//S contain the index of the coin to be included
	//in the optimal solution
	int S[A+1];
	
	//compute minimum number of coins required
	coinChange(d, C, S, N, A);

	//display the minimum number of coins required to
	//make change for amount A
	cout<<endl<<C[A]<<endl;
	
	//display the coins used in the optimal solution
	coinSet(d, S, A);
		
	return 0;
}


