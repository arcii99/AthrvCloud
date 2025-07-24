//FormAI DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int binary_search(int array[], int size, int key)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;
        if(array[mid] < key)
            low = mid + 1;
        else if(array[mid] > key)
            high = mid - 1;
        else
            return mid;
    }

    return -1; /* key not found */
}

int main(void)
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Array:\n");

    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    int key;

    printf("Enter a key to search for: ");
    scanf("%d", &key);

    int index = binary_search(array, size, key);

    if(index != -1)
        printf("Found at index %d\n", index);
    else
        printf("Not found\n");

    return EXIT_SUCCESS;
}