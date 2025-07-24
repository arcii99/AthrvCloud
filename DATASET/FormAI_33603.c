//FormAI DATASET v1.0 Category: Searching algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

// Function to search for an element in an array
int search(int arr[], int n, int x){
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == x)
            return i;
    }
    return -1; // If element not found, return -1
}

int main(){
    int arr[SIZE], n, x, i, pos;

    // Generate random numbers and fill the array
    srand(time(NULL));
    for (i = 0; i < SIZE; i++){
        arr[i] = rand() % 1000;
    }

    printf("Enter a number to search: ");
    scanf("%d", &x);

    // Call the search function to find the element and its position
    pos = search(arr, SIZE, x);

    if (pos == -1)
        printf("%d not found in the array.", x);
    else
        printf("%d found at position %d.", x, pos+1);

    return 0;
}