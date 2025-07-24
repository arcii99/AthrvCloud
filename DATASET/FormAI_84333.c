//FormAI DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>

int puzzleSearch(int arr[], int n, int key) {
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        int guess = arr[mid];

        if (guess == key) {
            printf("Congratulations! You found the key!\n");
            return mid;
        }
        else if (guess < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    printf("Sorry, the key is not in the array.\n");
    return -1;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Welcome to the Puzzle Search Game!\n");
    printf("Here's your array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Please enter the number you're looking for: ");
    scanf("%d", &key);

    puzzleSearch(arr, n, key);

    return 0;
}