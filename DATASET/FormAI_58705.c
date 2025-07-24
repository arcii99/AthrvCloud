//FormAI DATASET v1.0 Category: Sorting ; Style: calm
#include<stdio.h>

int main() {
    int n, i, j, temp;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the integers you want to sort:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray before sorting: \n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    //Sorting the array in ascending order
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }   
    }
    
    printf("\n\nArray after sorting in ascending order: \n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    //Sorting the array in descending order
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }   
    }
    
    printf("\n\nArray after sorting in descending order: \n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}