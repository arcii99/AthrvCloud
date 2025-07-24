//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000 //Define size of data array

//Function to initialize array with random integers between 1 and 1000
void initialize(int* data) {
    for(int i=0; i<SIZE; i++) {
        data[i] = rand()%1000 + 1;
    }
}

//Function to perform selection sort on the array
void selectionSort(int* data) {
    int minIndex;
    int temp;
    for(int i=0; i<SIZE-1; i++) {
        minIndex = i;
        for(int j=i+1; j<SIZE; j++) {
            if(data[j] < data[minIndex]) {
                minIndex = j;
            }
        }
        temp = data[i];
        data[i] = data[minIndex];
        data[minIndex] = temp;
    }
}

//Function to print the sorted array
void printData(int* data) {
    for(int i=0; i<SIZE; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    clock_t start, end; //Variables to measure the time taken by the program
    int data[SIZE]; //Array to hold data

    //Initialize the array with random integers
    initialize(data);

    //Print the unsorted data
    printf("Unsorted data:\n");
    printData(data);

    //Perform selection sort on the data
    printf("Sorting data...\n");
    start = clock(); //Start measuring time
    selectionSort(data);
    end = clock(); //Stop measuring time
    printf("Data sorted successfully in %ld ms\n", (end-start)*1000/CLOCKS_PER_SEC);

    //Print the sorted data
    printf("Sorted data:\n");
    printData(data);

    return 0;
}