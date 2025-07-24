//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void sort_array(int arr[], int size);

int main(){
    int arr[MAX_SIZE];
    int size = 0;

    // Generate random values for array
    srand(time(NULL));
    for(int i=0; i<MAX_SIZE; i++){
        arr[i] = rand() % MAX_SIZE;
    }
    size = MAX_SIZE;

    sort_array(arr, size);

    return 0;
}

// Quick sort algorithm to sort the array
void sort_array(int arr[], int size){
    int lo = 0, hi = size-1;
    int stack[hi-lo+1]; // Stack to store the partition sizes
    int top = -1;
  
    // Initialize the stack
    stack[++top] = lo;
    stack[++top] = hi;

    while(top >= 0){
        // Pop the partition sizes from stack
        hi = stack[top--];
        lo = stack[top--];
        
        // Partition
        int pivot = arr[hi];
        int i = lo-1;
        for(int j=lo; j<=hi-1; j++){
            if(arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[hi];
        arr[hi] = temp;

        // Push the partition sizes into stack
        if((i - lo) > 1){
            stack[++top] = lo;
            stack[++top] = i-1;
        }

        if((hi - (i+1)) > 1){
            stack[++top] = i+1;
            stack[++top] = hi;
        }
    }
}