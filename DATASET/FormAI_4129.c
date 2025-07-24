//FormAI DATASET v1.0 Category: Benchmarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100000
#define MAX_ITERATIONS 10000

void bubble_sort(int *numbers, int size){
    int temp;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(numbers[j] > numbers[j+1]){
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }
}

void insertion_sort(int *numbers, int size){
    int i, j, temp;
    for(i = 1; i < size; i++){
        temp = numbers[i];
        j = i - 1;
        while((temp < numbers[j]) && (j >= 0)){
            numbers[j+1] = numbers[j];
            j = j - 1;
        }
        numbers[j+1] = temp;
    }
}

int main(){
    int numbers[MAX_NUMBERS];
    clock_t start_time, end_time;
    double bubble_sort_time, insertion_sort_time;
    srand(time(0));

    // Fill array with random numbers
    for(int i = 0; i < MAX_NUMBERS; i++){
        numbers[i] = rand() % 100;
    }

    // Benchmark bubble sort
    start_time = clock();
    for(int i = 0; i < MAX_ITERATIONS; i++){
        bubble_sort(numbers, MAX_NUMBERS);
    }
    end_time = clock();
    bubble_sort_time = ((double)(end_time - start_time)/(CLOCKS_PER_SEC * MAX_ITERATIONS)) * 1000;

    // Benchmark insertion sort
    start_time = clock();
    for(int i = 0; i < MAX_ITERATIONS; i++){
        insertion_sort(numbers, MAX_NUMBERS);
    }
    end_time = clock();
    insertion_sort_time = ((double)(end_time - start_time)/(CLOCKS_PER_SEC * MAX_ITERATIONS)) * 1000;

    printf("Bubble sort average time: %fms\n", bubble_sort_time);
    printf("Insertion sort average time: %fms\n", insertion_sort_time);

    return 0;
}