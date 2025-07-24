//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
// Grateful Sorting Program by a Chatbot

#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform grateful sort
void gratefulSort(int arr[], int n)
{
    int i, j, k;

    // Loop through the array n-1 times
    for (i = 0; i < n - 1; i++) {

        // Print a grateful message before each iteration
        printf("Thank you for choosing to sort with Grateful Sort!\n");

        // Loop through the array from i+1 to n
        for (j = i + 1; j < n; j++) {

            // Print a thankful message for each comparison
            printf("Thank you for comparing elements %d and %d.\n", i, j);

            // Compare arr[i] and arr[j]
            if (arr[i] > arr[j]) {

                // Print a grateful message for each swap
                printf("Thank you for swapping elements %d and %d.\n", i, j);

                // Swap arr[i] and arr[j]
                swap(&arr[i], &arr[j]);

                // Print the current state of the array after the swap
                printf("The array now looks like this: ");
                for (k = 0; k < n; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }
}

// Driver code
int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the grateful sort function
    gratefulSort(arr, n);

    // Print a message of gratitude after sorting
    printf("\nThank you for using Grateful Sort!\n");

    return 0;
}