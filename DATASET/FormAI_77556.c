//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void init_array(int *arr, int size)
{
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void bubble_sort(int *arr, int size)
{
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int *arr, int size)
{
    int i, j, min_index, temp;
    for (i = 0; i < size-1; i++) {
        min_index = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void insertion_sort(int *arr, int size)
{
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(void)
{
    int arr[ARRAY_SIZE];
    init_array(arr, ARRAY_SIZE);

    clock_t t1_bubble, t2_bubble;
    t1_bubble = clock();
    bubble_sort(arr, ARRAY_SIZE);
    t2_bubble = clock();

    printf("Bubble sort: %f seconds\n", (double)(t2_bubble - t1_bubble) / CLOCKS_PER_SEC);

    clock_t t1_selection, t2_selection;
    t1_selection = clock();
    selection_sort(arr, ARRAY_SIZE);
    t2_selection = clock();

    printf("Selection sort: %f seconds\n", (double)(t2_selection - t1_selection) / CLOCKS_PER_SEC);

    clock_t t1_insertion, t2_insertion;
    t1_insertion = clock();
    insertion_sort(arr, ARRAY_SIZE);
    t2_insertion = clock();

    printf("Insertion sort: %f seconds\n", (double)(t2_insertion - t1_insertion) / CLOCKS_PER_SEC);

    return 0;
}