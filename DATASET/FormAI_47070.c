//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
#include <stdio.h>

/*
    A peaceful sorting program that sorts a given array of integers in ascending order using 
    bubble sort algorithm. It compares each element of the array with its adjacent element 
    and swaps them if they are not in correct order.
*/

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++) {         
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                //swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        } 
    }
}

int main()
{
    int arr[] = {77, 32, 14, 66, 89, 22, 68, 49, 55, 27};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, n);  

    printf("\nAfter sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}