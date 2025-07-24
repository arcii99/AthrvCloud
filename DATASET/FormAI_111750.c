//FormAI DATASET v1.0 Category: Sorting ; Style: realistic
#include <stdio.h>

// function signature
void bubble_sort(int arr[], int n);

int main() {
    int n, i;
    printf("Enter number of elements of the array: ");
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // sorting the array using bubble sort
    bubble_sort(arr, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}