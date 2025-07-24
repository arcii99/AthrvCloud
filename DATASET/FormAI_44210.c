//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    printf("Greetings! Today we will be sorting an array of integers using the bubble sort algorithm.\n");

    int arr[] = {23, 35, 11, 62, 8, 49};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("The original array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bubble_sort(arr, n);

    printf("\nThe sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nThank you for running this program! I hope you enjoyed watching the bubble sort algorithm in action.\n");

    return 0;
}