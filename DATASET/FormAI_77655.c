//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int shapeShift(int *array, int size, int key)
{
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == key) {
            return mid;
        }
        if (array[left] <= array[mid]) {
            if (key >= array[left] && key < array[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (key > array[mid] && key <= array[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int size, key, result;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int *array = (int *) calloc(size, sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    result = shapeShift(array, size, key);
    if (result == -1) {
        printf("Element not found!\n");
    } else {
        printf("Element found at index %d\n", result);
    }
    free(array);
    return 0;
}