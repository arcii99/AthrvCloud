//FormAI DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h>

//Function to perform the bubble sort algorithm
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//Main function to initialize the array, sort and print the results
int main()
{
    int i;
    int arr[10] = {5, 7, 3, 2, 9, 1, 8, 4, 6, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    //Print the unsorted array
    printf("Unsorted array: {");
    for(i=0; i<n; i++){
        if(i!= n-1) printf("%d, ", arr[i]);
        else printf("%d}", arr[i]);
    }

    //Sort the array using the bubble sort algorithm
    bubbleSort(arr, n);

    //Print the sorted array
    printf("\nSorted array: {");
    for(i=0; i<n; i++){
        if(i!= n-1) printf("%d, ", arr[i]);
        else printf("%d}", arr[i]);
    }

    return 0;
}