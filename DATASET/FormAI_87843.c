//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void bucketSort(int arr[], int n) 
{ 
    int i, j; 
    int count[n]; 
    for (i = 0; i < n; i++) 
        count[i] = 0; 

    for (i = 0; i < n; i++) 
        (count[arr[i]])++; 

    for (i = 0, j = 0; i < n; i++) 
        for(; count[i] > 0; (count[i])--) 
            arr[j++] = i; 
} 

int main() 
{ 
    int arr[100], n, i;
    srand(time(NULL));
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Initial array: ");
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    
    bucketSort(arr, n); 
    
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    return 0; 
}