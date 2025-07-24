//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main() {
    printf("Let's sort some numbers with a cheerful attitude!\n");
    int i, n;
    printf("How many numbers would you like to sort? ");
    scanf("%d", &n);
    int arr[n];
    printf("Please enter %d numbers to sort:\n", n);
    for (i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Your unsorted array: \n");
    for (i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nNow let's sort it...\n");
    bubbleSort(arr, n);
    printf("Your sorted array: \n");
    for (i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nCongratulations, we did it! Keep sorting with a smile! :)\n");
    return 0;
}