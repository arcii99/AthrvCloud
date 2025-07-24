//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main(){
    int arr[SIZE];
    int i, j, temp;

    //Fill array with random integers
    srand(time(NULL));
    for(i = 0; i < SIZE; i++){
        arr[i] = rand() % 1000;
    }

    //Sort the array using bubble sort algorithm
    for(i = 0; i < SIZE-1; i++){
        for(j = 0; j < SIZE-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    //Print the sorted array
    for(i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}