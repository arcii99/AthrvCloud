//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Cyberpunk
#include <stdio.h>

// Declare a function called linear_search
int linear_search(int array[], int key, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == key) {
            // Key found!
            return i;
        }
    }
    // Key not found :(
    return -1;
}

int main() {
    printf("Enter the number of elements in the array: ");
    int size;
    scanf("%d", &size);

    int array[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the key to search for: ");
    int key;
    scanf("%d", &key);

    int index = linear_search(array, key, size);

    if (index == -1) {
        printf("Sorry, couldn't find the key in the array.\n");
    } else {
        printf("Key found at index %d in the array.\n", index);
    }

    return 0;
}