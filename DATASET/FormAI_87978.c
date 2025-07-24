//FormAI DATASET v1.0 Category: Benchmarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10000

void generateRandomArray(int *array, int size);
void insertionSort(int *array, int size);
void quickSort(int *array, int low, int high);
int partition(int *array, int low, int high);
void swap(int *a, int *b);

int main(){
    int array[ARRAY_SIZE];
    double time_spent;
    clock_t start, end;
    generateRandomArray(array, ARRAY_SIZE);

    start = clock();
    insertionSort(array, ARRAY_SIZE);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds to execute \n", time_spent);

    generateRandomArray(array, ARRAY_SIZE);

    start = clock();
    quickSort(array, 0, ARRAY_SIZE - 1);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort took %f seconds to execute \n", time_spent);
}

void generateRandomArray(int *array, int size){
    srand((unsigned) time(NULL));
    for(int i = 0; i < size; i++){
        array[i] = rand() % (size * 10);
    }
}

void insertionSort(int *array, int size){
    for(int i = 1; i < size; i++){
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > key){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void quickSort(int *array, int low, int high){
    if(low < high){
        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int partition(int *array, int low, int high){
    int pivot = array[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if(array[j] < pivot){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);

    return i + 1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}