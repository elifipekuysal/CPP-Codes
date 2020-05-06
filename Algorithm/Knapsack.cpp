#include <iostream>

using namespace std;

int max(int a, int b) {
        return (a > b) ? a : b;
}

void variables(int number[], int weight[], int value[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> number[i];
        cin >> weight[i];
        cin >> value[i];
    }	
}

void knapSack(int W, int weight[], int value[], int n) {
    int i, w;
    int K[n + 1][W + 1];
    int items[n] = {0};

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    for(int i = n, j = W; i > 0; i--){
		if(K[i][j] - K[i-1][j - weight[i - 1]] == value[i-1]){
	        items[i-1] = 1;
            j = j - weight[i-1]; 
        } 
    } 
       
    cout << K[n][W] << endl; 
    for(int i =0 ; i < n; i++){
      if(items[i] != 0){
            cout << 1+i << " ";
          }
    }
    cout << endl;
}


int main() {
    int n, W;
    cin >> n;
    cin >> W;
    int number[n], value[n], weight[n];

	variables(number,weight,value,n);

    knapSack(W, weight, value, n);   

    return 0;
}
