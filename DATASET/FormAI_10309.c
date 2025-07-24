//FormAI DATASET v1.0 Category: Benchmarking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int size = 1000000;
    int arr[size];

    // Filling the array with random integers 
    srand(time(NULL));
    for(int i=0; i<size; i++) {
        arr[i] = rand()%size;
    }

    // Bubble sort algorithm 
    clock_t start_bubble = clock();
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t end_bubble = clock();
    printf("Bubble sort took %f seconds.\n", (double)(end_bubble - start_bubble)/CLOCKS_PER_SEC);

    // Quick Sort algorithm 
    clock_t start_quick = clock();
    int left, right, pivot, temp;
    int stack[size];
    int top = -1;
    stack[++top] = 0;
    stack[++top] = size-1;
    while(top >= 0) {
        right = stack[top--];
        left = stack[top--];
        pivot = arr[(left+right)/2];
        while(left <= right) {
            while(arr[left] < pivot)
                left++;
            while(arr[right] > pivot)
                right--;
            if(left <= right) {
                temp = arr[left];
                arr[left++] = arr[right];
                arr[right--] = temp;
            }
        }
        if(right > 0) {
            stack[++top] = 0;
            stack[++top] = right;
        } 
    }
    clock_t end_quick = clock();
    printf("Quick sort took %f seconds.\n", (double)(end_quick - start_quick)/CLOCKS_PER_SEC);

    return 0;
}