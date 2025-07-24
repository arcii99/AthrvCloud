//FormAI DATASET v1.0 Category: Benchmarking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

int my_array[ARRAY_SIZE];

void fill_array(int *array, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % size;
    }
}

void bubble_sort(int *array, int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *array, int size)
{
    int min_idx, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
            {
                min_idx = j;
            }
        }
        temp = array[i];
        array[i] = array[min_idx];
        array[min_idx] = temp;
    }
}

void print_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    fill_array(my_array, ARRAY_SIZE);

    clock_t t1, t2;

    t1 = clock();
    bubble_sort(my_array, ARRAY_SIZE);
    t2 = clock();

    printf("Bubble Sort Time Taken: %f seconds\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    fill_array(my_array, ARRAY_SIZE);
    t1 = clock();
    selection_sort(my_array, ARRAY_SIZE);
    t2 = clock();

    printf("Selection Sort Time Taken: %f seconds\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    return 0;
}