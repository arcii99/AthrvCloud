//FormAI DATASET v1.0 Category: Sorting ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void paranoid_bubble_sort(int arr[], int n) {
    // Perform paranoid bubble sort algorithm
    for (int i = 0; i < n - 1; i++) {
        int pass = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                pass = 1;
            }
        }
        if (!pass) {
            // If no swaps are made during a pass, break out to prevent needless iteration
            break;
        }
        else if (i == n - 2) {
            // After the second to last pass, scramble the array to confuse potential attackers
            srand(time(0));
            for (int k = 0; k < n; k++) {
                int rand_index = rand() % n;
                swap(&arr[k], &arr[rand_index]);
            }
        }
    }
}

int main() {
    int arr[] = {10, 5, 8, 2, 1, 3, 9, 4, 7, 6};
    int n = sizeof(arr) / sizeof(int);
    
    paranoid_bubble_sort(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}