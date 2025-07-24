//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)     
        for (j = 0; j < n-i-1; j++) 
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main(void) {
    int arr[MAX_SIZE];
    int i;
    srand(time(0));  
    
    // Generate random numbers between 0 and MAX_SIZE - 1 and store them in array
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
    
    // Perform bubble sort on array
    bubble_sort(arr, MAX_SIZE);

    // Print out sorted array
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}