//FormAI DATASET v1.0 Category: Sorting ; Style: Linus Torvalds
#include <stdio.h>

/**
 * swap - helper function to swap two elements in an array
 * @a: pointer to first element
 * @b: pointer to second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * bubble_sort - sorts an array using the bubble sort algorithm
 * @array: pointer to array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
    unsigned int i, j;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main(void)
{
    int array[] = {64, 25, 12, 22, 11};
    size_t size = sizeof(array) / sizeof(array[0]);
    unsigned int i;

    printf("Original array: ");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);

    bubble_sort(array, size);

    printf("\nSorted array: ");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);

    return 0;
}