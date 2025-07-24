//FormAI DATASET v1.0 Category: Sorting ; Style: statistical
/**
 * @file sort.c
 * @brief A program that demonstrates four sorting algorithms.
 *
 * This program demonstrates four common sorting algorithms:
 * bubble sort, insertion sort, selection sort, and quick sort.
 * It generates a random array of integers and sorts them using each of the
 * four sorting algorithms, then prints the sorted arrays along with the
 * number of comparisons and swaps performed by each algorithm.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100 // size of the array to be sorted

/**
 * @brief Swaps two integers in an array.
 * 
 * @param array The array containing the integers to be swapped.
 * @param i The index of the first integer.
 * @param j The index of the second integer.
 */
void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

/**
 * @brief Performs bubble sort on an array of integers.
 *
 * @param array The array to be sorted.
 * @param size The size of the array.
 * @return The number of comparisons and swaps performed.
 */
int bubbleSort(int array[], int size)
{
    int i, j, count = 0;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                swap(array, j, j + 1);
                count++;
            }
            count++;
        }
    }

    return count;
}

/**
 * @brief Performs insertion sort on an array of integers.
 *
 * @param array The array to be sorted.
 * @param size The size of the array.
 * @return The number of comparisons and swaps performed.
 */
int insertionSort(int array[], int size)
{
    int i, j, temp, count = 0;

    for (i = 1; i < size; i++) {
        temp = array[i];
        for (j = i - 1; j >= 0 && array[j] > temp; j--) {
            array[j + 1] = array[j];
            count++;
        }
        array[j + 1] = temp;
        count++;
    }

    return count;
}

/**
 * @brief Performs selection sort on an array of integers.
 * 
 * @param array The array to be sorted.
 * @param size The size of the array.
 * @return The number of comparisons and swaps performed.
 */
int selectionSort(int array[], int size)
{
    int i, j, minIndex, count = 0;

    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
            count++;
        }
        if (minIndex != i) {
            swap(array, i, minIndex);
            count++;
        }
    }

    return count;
}

/**
 * @brief Performs quick sort on an array of integers.
 * 
 * @param array The array to be sorted.
 * @param left The index of the first element in the subarray to be sorted.
 * @param right The index of the last element in the subarray to be sorted.
 * @param count A pointer to an integer that keeps track of the number of
 *              comparisons and swaps performed.
 */
void quickSort(int array[], int left, int right, int* count)
{
    int i, j, pivot;

    if (left >= right) {
        return;
    }

    pivot = array[right];
    i = left - 1;

    for (j = left; j < right; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array, i, j);
            (*count)++;
        }
        (*count)++;
    }

    swap(array, i + 1, right);
    (*count)++;

    quickSort(array, left, i, count);
    quickSort(array, i + 2, right, count);
}

int main()
{
    int i;
    int array[SIZE];
    int count;

    srand(time(NULL));

    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    printf("Original array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    count = bubbleSort(array, SIZE);
    printf("Bubble sort:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\nComparisons and swaps: %d\n\n", count);

    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    count = insertionSort(array, SIZE);
    printf("Insertion sort:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\nComparisons and swaps: %d\n\n", count);

    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    count = selectionSort(array, SIZE);
    printf("Selection sort:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\nComparisons and swaps: %d\n\n", count);

    for (i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }

    count = 0;
    quickSort(array, 0, SIZE - 1, &count);
    printf("Quick sort:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\nComparisons and swaps: %d\n\n", count);

    return 0;
}