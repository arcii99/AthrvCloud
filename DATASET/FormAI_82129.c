//FormAI DATASET v1.0 Category: Sorting ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ARRAY_SIZE 100

//Structure to be used by the threads for sorting each half of the array
typedef struct
{
    int thread_id;
    int *array;
    int start;
    int end;
} SortThreadParams;

//Function Declarations
void merge(int *array, int start, int mid, int end);
void *threaded_sort(void *params);
void quicksort(int *array, int start, int end);
void display_array(int *array, int size);

int main()
{
    int num_array[ARRAY_SIZE];

    //Seed the random number generator
    srand(time(NULL));

    printf("Original array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        num_array[i] = rand() % 100;
        printf("%d ", num_array[i]);
    }

    //Divide the array into two halves and start a thread for each half to sort the array
    SortThreadParams left_half_params = {1, num_array, 0, ARRAY_SIZE / 2};
    SortThreadParams right_half_params = {2, num_array, ARRAY_SIZE / 2, ARRAY_SIZE};

    pthread_t left_thread;
    pthread_t right_thread;

    pthread_create(&left_thread, NULL, threaded_sort, &left_half_params);
    pthread_create(&right_thread, NULL, threaded_sort, &right_half_params);
    pthread_join(left_thread, NULL);
    pthread_join(right_thread, NULL);

    //Merge the sorted halves of the array
    merge(num_array, 0, ARRAY_SIZE / 2, ARRAY_SIZE);

    printf("\nSorted array:\n");
    display_array(num_array, ARRAY_SIZE);

    return 0;
}

//Merging of the sorted halves of the array
void merge(int *array, int start, int mid, int end)
{
    //Temporary array to hold the merged subarrays
    int *temp_array = malloc((end - start) * sizeof(int));

    int i = start;
    int j = mid;
    int k = 0;

    //Merge the two subarrays into a temporary array until one subarray is exhausted
    while (i < mid && j < end)
    {
        if (array[i] < array[j])
        {
            temp_array[k] = array[i];
            i++;
        }
        else
        {
            temp_array[k] = array[j];
            j++;
        }
        k++;
    }

    //Copy remaining elements of subarray1 to the temporary array if any
    while (i < mid)
    {
        temp_array[k] = array[i];
        i++;
        k++;
    }

    //Copy remaining elements of subarray2 to the temporary array if any
    while (j < end)
    {
        temp_array[k] = array[j];
        j++;
        k++;
    }

    //Copy the temporary array back to the original array
    for (int x = 0; x < k; x++)
    {
        array[start + x] = temp_array[x];
    }

    free(temp_array);
}

//Thread function that calls the quicksort algorithm on a subarray of the main array
void *threaded_sort(void *params)
{
    SortThreadParams *sort_params = (SortThreadParams *)params;

    printf("\nSorting thread %d started:\n", sort_params->thread_id);
    display_array(sort_params->array + sort_params->start, sort_params->end - sort_params->start);

    quicksort(sort_params->array, sort_params->start, sort_params->end - 1);

    printf("\nSorting thread %d finished:\n", sort_params->thread_id);
    display_array(sort_params->array + sort_params->start, sort_params->end - sort_params->start);

    pthread_exit(NULL);
}

//Recursive divide-and-conquer quicksort implementation
void quicksort(int *array, int start, int end)
{
    if (start < end)
    {
        int pivot = start;
        int i = start + 1;
        int j = end;

        //Partition the array around the pivot element
        while (i < j)
        {
            while (i <= end && array[i] <= array[pivot])
                i++;
            while (j >= start + 1 && array[j] > array[pivot])
                j--;
            if (i < j)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        //Place the pivot element in the correct position of the sorted array
        int temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;

        //Recursively sort the left half and right half of the array
        quicksort(array, start, j - 1);
        quicksort(array, j + 1, end);
    }
}

//Display array function for debugging purposes
void display_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}