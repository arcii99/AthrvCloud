//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Sorting Circus!\n\n");

    // Count length of array to sort
    int length;
    printf("How many numbers do you want to sort?\n");
    scanf("%d", &length);

    // Create and assign random values to array
    int arr[length];
    srand(time(NULL));
    printf("\nYour unsorted numbers:\n");
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }

    // Choose a sorting algorithm
    printf("\n\nChoose a sorting algorithm to perform:\n1. Bubble Sort\n2. Insertion Sort\n3. Quick Sort\n");
    int choice;
    scanf("%d", &choice);

    // Perform chosen sorting algorithm
    switch (choice) {
        case 1:
            printf("\nPerforming Bubble Sort... Hold on to your seats!\n");
            for (int i = 0; i < length - 1; i++) {
                for (int j = 0; j < length - 1 - i; j++) {
                    if (arr[j] > arr[j + 1]) {
                        // Swap values
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            break;
        case 2:
            printf("\nPerforming Insertion Sort... Be sure to buckle up!\n");
            for (int i = 1; i < length; i++) {
                int key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
            break;
        case 3:
            printf("\nPerforming Quick Sort... Watch out for that wild pivot!\n");
            quickSort(arr, 0, length - 1);
            break;
        default:
            printf("\nOops, something went wrong. Let's try this again.\n");
            main();
            exit(0);
    }

    // Display sorted array
    printf("\nYour sorted numbers:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nThanks for joining us at the Sorting Circus! Come back soon!\n");

    return 0;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap values
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap values
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}