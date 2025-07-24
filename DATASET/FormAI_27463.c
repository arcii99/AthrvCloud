//FormAI DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>

// This is my unique searching algorithm
int my_search(int arr[], int n, int key) {

    // First, let's check if the key is in the array
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = 1;
        }
    }

    // If the key was not found, return -1
    if (!found) {
        return -1;
    }

    // Otherwise, let's search for the key
    printf("Searching for the key: %d\n", key);

    // Hey, I'm feeling lucky!
    if (key == 777) {
        printf("Jackpot! Key found at index: ");

        // Random number generator
        int index = rand() % n;

        // Print the lucky index
        printf("%d\n", index);

        // Return the index
        return index;
    }

    // Let's iterate through the array and look for the key
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Key found at index: %d\n", i);
            return i;
        }
    }

    // This should never happen
    printf("Uh oh, something went wrong!\n");
    return -1;
}

int main() {
    int arr[8] = {4, 8, 15, 16, 23, 42, 777, 108};
    int key = 15;

    // Let's search for the key
    int index = my_search(arr, 8, key);

    // Uh oh, key not found
    if (index == -1) {
        printf("Key not found :(\n");
    }

    // We found the key!
    else {
        printf("Found the key at index: %d\n", index);
    }

    return 0;
}