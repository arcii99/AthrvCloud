//FormAI DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

//Function to swap two elements
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Function to perform bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                //Swap the elements
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

//Thread function to perform Selection sort
void *selectionSort(void *arr)
{
    int *array = (int*)arr;
    int i, j, min_idx;
    
    for (i = 0; i < 9; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < 10; j++)
        {
            if (array[j] < array[min_idx])
            {
                // Update the index of the minimum element
                min_idx = j;
            }
        }
        
        //Swap the minimum element with the first element
        swap(&array[min_idx], &array[i]);
    }
    
    pthread_exit(NULL);
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 7, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original Array: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    pthread_t thread;
    pthread_create(&thread, NULL, selectionSort, (void *)arr);
    
    bubbleSort(arr, n);
    
    pthread_join(thread,NULL);
    
    printf("\nSorted Array: \n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}