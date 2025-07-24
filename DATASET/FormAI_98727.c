//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h>

//Brave Searching Algorithm
int brave_search(int arr[], int n, int key) {
    int i = 0;
    while (i < n) {
        if (arr[i] == key) {
            printf("Key Found at position %d!\n", i + 1);
            return 1;
        }
        i += abs(key - arr[i]);
    }
    printf("Key not found!\n");
    return 0;
}

int main() {
    int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(int);
    int key = 11;

    printf("Running the Brave Searching Algorithm!\n");
    brave_search(arr, n, key);

    return 0;
}