//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000000
#define ITERATIONS 10

void bubble_sort(int* arr, int len){
    int i, j, temp;
    for(i=0; i<len; i++){
        for(j=0; j<len-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[SIZE];
    int i, j;
    double time_taken[ITERATIONS];
    
    srand(time(0));
    for(i=0; i<SIZE; i++){
        arr[i] = rand()%SIZE;
    }
    
    printf("BENCHMARKING BUBBLE SORT\n\n");
    for(i=0; i<ITERATIONS; i++){
        int temp_arr[SIZE];
        memcpy(temp_arr, arr, sizeof arr);
        clock_t t;
        t = clock();
        bubble_sort(temp_arr, SIZE);
        t = clock() - t;
        double time_taken_single = ((double)t)/CLOCKS_PER_SEC;
        printf("Iteration %d:\t%f seconds\n", i+1, time_taken_single);
        time_taken[i] = time_taken_single;
    }
    
    double sum = 0, avg_time_taken;
    for(i=0; i<ITERATIONS; i++){
        sum += time_taken[i];
    }
    avg_time_taken = sum/ITERATIONS;
    
    printf("\nAVERAGE TIME TAKEN:\t%f seconds\n", avg_time_taken);
    
    return 0;
}