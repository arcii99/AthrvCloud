//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BUCKET_SIZE 10
#define ARRAY_SIZE 20

// function to generate random numbers
int random_number(){
    return (rand() % 100);
}

// function to print an array
void print_array(int *arr, int size){
    printf("[ ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// function to swap two numbers in an array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// C bucket sort implementation
void bucket_sort(int *arr, int size){
    int i, j;
    int bucket[BUCKET_SIZE];
    for(i = 0; i < BUCKET_SIZE; i++){
        bucket[i] = 0;
    }
    for(i = 0; i < size; i++){
        (bucket[arr[i] / BUCKET_SIZE])++;
    }
    for(i = 0, j = 0; i < BUCKET_SIZE; i++){
        while((bucket[i]--) > 0){
            arr[j++] = (i * BUCKET_SIZE);
        }
    }
}

int main(){

    printf("Irregular C Bucket Sort Implementation Example\n");

    // seed for random number generation
    srand(time(NULL));

    int arr[ARRAY_SIZE];

    // generate a random array
    for(int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = random_number();
    }

    printf("Initial Array: ");
    print_array(arr, ARRAY_SIZE);

    // sort the array using bucket sort
    bucket_sort(arr, ARRAY_SIZE);

    printf("Sorted Array: ");
    print_array(arr, ARRAY_SIZE);

    return 0;
}