#include <iostream>
#define SIZE 10

using namespace std;

int getHundreds(int number) {  //Get the hundreds digit
	return number / 100; 
}

int getTens(int number) {  //Get the tens digit
	return (number % 100) / 10; 
}

int getOnes(int number) {  //Get the ones digit
	return (number % 10) / 1; 
}

void resetCountSort(int arr[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            arr[i][j] = -1;
        }
    }
}

int calculateError(int S1[], int S2[]) {  //Calculate error percent between Radix and Hollerith Sort
    int errorCounter= 0;
    int count= 0;
    for(int count= 0; count < SIZE; count++){
        if( S1[count] != S2[count]){
            errorCounter++;
        }
    }

    float error;

    // Calculating error
    cout<<"Hollerith algoritmasi %" << errorCounter*10 << " hata" << endl;
}

void printS1nS2(int S1[], int S2[]) {  //Print sorted arrays with Radix and Hollerith
	for(int i=0; i<SIZE; i++) {
		cout<<S1[i]<<" ";
	}

	cout<<endl;
	for(int i=0; i<SIZE; i++) {
		cout<<S2[i]<<" ";
	}
	cout<<endl;
}

void Radix(int S1[]);  //Define Radix Sort function for S1
void Hollerith(int S2[]);  //Define Hollerith Sort function for S2


int main(){
    int input[SIZE],S1[SIZE], S2[SIZE];   //Create arrays for sorting

    for(int i= 0; i < SIZE; i++)  //Assign the input values to arrays
    	cin >> input[i];
    	
    for(int i= 0; i < SIZE; i++)  //Assign the input values to radix sort array
    	S1[i]= input[i];
    	
    for(int i= 0; i < SIZE; i++)  //Assign the input values to hollerith sort array
    	S2[i]= input[i];


	Radix(S1);  //Radix sorting S1 array
	Hollerith(S2);  //Hollerith sorting S2 array

	printS1nS2(S1, S2);  //Print the radix sorted and the hollerith sorted array
	calculateError(S1, S2);  //Calculate error size

	return 0;
}

void Radix(int S1[]) {  //Radix Sort
    int dummy_counter;
	int count_sort[SIZE][SIZE];

    resetCountSort( count_sort);

    for(int i = 0; i < SIZE; i++){
        count_sort[getOnes(S1[i])][i] = S1[i];
    }

    dummy_counter = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(count_sort[i][j] != -1){
                S1[dummy_counter] = count_sort[i][j];
                dummy_counter++;
            }
        }
    } resetCountSort( count_sort );

    for(int i = 0; i < SIZE; i++){
        count_sort[getTens(S1[i])][i] = S1[i];
    }

    dummy_counter = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(count_sort[i][j] != -1){
                S1[dummy_counter] = count_sort[i][j];
                dummy_counter++;
            }
        }
    } resetCountSort( count_sort);

    for(int i = 0; i < SIZE; i++){
        count_sort[getHundreds(S1[i])][i] = S1[i];
    }

    dummy_counter = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(count_sort[i][j] != -1){
                S1[dummy_counter] = count_sort[i][j];
                dummy_counter++;
            }
        }
    } resetCountSort( count_sort);
}

void Hollerith(int S2[]) {  //Hollerith Sort
    int dummy_counter;
   	int count_sort[SIZE][SIZE];

    resetCountSort( count_sort);

    for(int i = 0; i < SIZE; i++){
        count_sort[getHundreds(S2[i])][i] = S2[i];
    }

    dummy_counter = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(count_sort[i][j] != -1){
                S2[dummy_counter] = count_sort[i][j];
                dummy_counter++;
            }
        }
    } resetCountSort( count_sort );

    for(int i = 0; i < SIZE; i++){
        count_sort[getTens(S2[i])][i] = S2[i];
    }

    dummy_counter = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(count_sort[i][j] != -1){
                S2[dummy_counter] = count_sort[i][j];
                dummy_counter++;
            }
        }
    } resetCountSort( count_sort);

    for(int i = 0; i < SIZE; i++){
        count_sort[getOnes(S2[i])][i] = S2[i];
    }

    dummy_counter = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(count_sort[i][j] != -1){
                S2[dummy_counter] = count_sort[i][j];
                dummy_counter++;
            }
        }
    } resetCountSort( count_sort);
}
