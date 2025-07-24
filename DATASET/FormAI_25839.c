//FormAI DATASET v1.0 Category: Sorting ; Style: rigorous
#include<stdio.h>

/* Define the function to sort the array */
void quicksort(int* array, int low, int high) {
    int i = low, j = high, temp;
    int pivot = array[(low + high) / 2];

    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if (low < j)
        quicksort(array, low, j);
    if (i < high)
        quicksort(array, i, high);
}

/* Define the main function to test the sorting algorithm */
int main() {
    int array[] = {5, 3, 2, 4, 1};
    int i;

    printf("Before sorting: ");
    for (i = 0; i < 5; i++)
        printf("%d ", array[i]);

    quicksort(array, 0, 4);

    printf("\nAfter sorting: ");
    for (i = 0; i < 5; i++)
        printf("%d ", array[i]);

    return 0;
}