//FormAI DATASET v1.0 Category: Benchmarking ; Style: all-encompassing
#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 1000000    // Define the size of the array to be created

// This function generates an array with random integers
void generate_array(int array[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size;
    }
}

// This function sorts the array using bubble sort algorithm
void bubble_sort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// This function measures the time taken to execute the sorting algorithm
double measure_time(int array[], int size, void (*sorting_algorithm)(int*, int))
{
    clock_t start_time, end_time;
    start_time = clock();
    sorting_algorithm(array, size);
    end_time = clock();
    double time_taken = ((double) end_time - start_time) / CLOCKS_PER_SEC;
    return time_taken;
}

int main()
{
    int array[ARRAY_SIZE];
    generate_array(array, ARRAY_SIZE);

    // Bubble sort benchmark
    double bubble_sort_time = measure_time(array, ARRAY_SIZE, bubble_sort);
    printf("Bubble sort took %f seconds to sort an array of size %d\n", bubble_sort_time, ARRAY_SIZE);

    return 0;
}