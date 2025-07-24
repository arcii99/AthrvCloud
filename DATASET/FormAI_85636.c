//FormAI DATASET v1.0 Category: Benchmarking ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10000

int main(){

    clock_t start_t, end_t; // used to calculate the time taken by the program
    double total_t;
    int arr[SIZE];

    // initialising the array with random values
    for(int i=0; i<SIZE; i++){
        arr[i] = rand() % 100 + 1;
    }

    start_t = clock(); // starting the timer

    // sorting the array using bubble sort
    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    end_t = clock(); // stopping the timer

    total_t = ((double) (end_t - start_t)) / CLOCKS_PER_SEC;

    printf("Sorting of array completed in %f seconds\n", total_t);
    printf("Thank you for using our program!\n");

    return 0;
}