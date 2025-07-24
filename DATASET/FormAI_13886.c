//FormAI DATASET v1.0 Category: Searching algorithm ; Style: configurable
#include <stdio.h>

// Function to search an element in an array
int search(int arr[], int n, int num) {
    for (int i=0; i<n; i++) {
        if (arr[i] == num) {
            return i;   // Return the index of the element if found
        }
    }
    return -1;  // Return -1 if element not found
}

// Main function
int main() {
    int arr[] = {12, 54, 23, 87, 65, 43, 10, 17, 29};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num;

    printf("Enter a number to search: ");
    scanf("%d", &num);

    int index = search(arr, n, num);

    if (index != -1) {
        printf("%d found at index %d in the array.\n", num, index);
    } else {
        printf("%d not found in the array.\n", num);
    }

    return 0;
}