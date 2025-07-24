//FormAI DATASET v1.0 Category: Benchmarking ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 1000000

int main(){
    int array[MAX_SIZE], n=MAX_SIZE, i, j;
    clock_t start, end;
    double elapsed_time;

    //Generating random numbers and storing them in the array
    for(i=0;i<n;i++){
        array[i]=rand()%100;
    }

    //Bubble Sort
    start = clock();
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    //Calculating elapsed time for bubble sort
    end = clock();
    elapsed_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Elapsed time for Bubble Sort: %f\n", elapsed_time);

    //Selection Sort
    start = clock();
    for(i=0;i<n-1;i++){
        int min_index = i;
        for(j=i+1;j<n;j++){
            if(array[j]<array[min_index]){
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }

    //Calculating elapsed time for selection sort
    end = clock();
    elapsed_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Elapsed time for Selection Sort: %f\n", elapsed_time);

    //Insertion Sort
    start = clock();
    for(i=1;i<n;i++){
        int key = array[i];
        j = i-1;
        while(j>=0 && array[j]>key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

    //Calculating elapsed time for insertion sort
    end = clock();
    elapsed_time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Elapsed time for Insertion Sort: %f\n", elapsed_time);

    return 0;
}