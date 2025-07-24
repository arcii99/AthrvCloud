//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to find the maximum element in an array
int find_max(int arr[], int n){
    int i, max = arr[0];
    for (i = 1; i < n; i++){
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int main(){
    int i, n, max;
    // Take size of array as input from user
    printf("Enter size of array: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(sizeof(int) * n);
    srand(time(NULL));
    // Generate n random numbers and store them in the array
    for (i = 0; i < n; i++){
        arr[i] = rand() % 100 + 1;
    }
    // Find the maximum element in the array
    max = find_max(arr, n);
    printf("Maximum element in array: %d\n", max);
    // Free memory
    free(arr);
    return 0;
}