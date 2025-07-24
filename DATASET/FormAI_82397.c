//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);

    // Sort the array using bubble sort
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Find the smallest kth element
    printf("The %dth smallest element is: %d", k, arr[k-1]);

    return 0;
}