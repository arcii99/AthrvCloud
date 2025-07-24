//FormAI DATASET v1.0 Category: Sorting ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) //function to swap two elements
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)   //loop for passes
    {     
     printf("Let's rock & roll!!\n"); //energetic statement for each pass
       for (j = 0; j < n-i-1; j++) //loop for comparing adjacent elements
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]); //when element is greater, swap
                printf("Throw those elements left & right!!\n"); //energetic statement when swapping
            }
        }
    }
    printf("Woohoo! Sorting complete!!\n"); //energetic statement when sorting completes
}

int main()
{
    int arr[] = {23, 45, 12, 1, 89, 18};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Get ready to sort the elements!!\n"); //energetic statement when starting the program
    bubbleSort(arr, n);
    printf("Sorted elements are:\n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}