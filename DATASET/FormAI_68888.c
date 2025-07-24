//FormAI DATASET v1.0 Category: Benchmarking ; Style: secure
#include<stdio.h>
#include<time.h>

#define ARRAY_SIZE 1000000

// Function to generate a random array
void generate_array(int arr[])
{
    srand(time(NULL));
    for(int i=0; i<ARRAY_SIZE; i++)
    {
        arr[i] = rand()%100;
    }
}

// Function to perform selection sort
void selection_sort(int arr[])
{
    int min_idx;
    for (int i = 0; i < ARRAY_SIZE-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < ARRAY_SIZE; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Function to perform insertion sort
void insertion_sort(int arr[])
{
    int key, j;
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to print the time taken by a function
void measure_time(void (*func)(int[]), int arr[], char* func_name)
{
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    func(arr);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds\n", func_name, cpu_time_used);
}

int main()
{
    int arr[ARRAY_SIZE];

    generate_array(arr);
    measure_time(selection_sort, arr, "Selection sort");

    generate_array(arr);
    measure_time(insertion_sort, arr, "Insertion sort");

    return 0;
}