//FormAI DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>

int search(int arr[], int n, int x) { 
    int i; 

    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 

    return -1; 
} 

int main() {
    int arr[] = {2, 4, 6, 8, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 6; 
    int index = search(arr, n, x); 
    if (index == -1) 
        printf("Sorry, %d is not present in the array.", x); 
    else
        printf("Hurray! %d is present at position %d of the array.", x, index+1);
    return 0;
}