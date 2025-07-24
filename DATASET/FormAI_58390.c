//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Oh my goodness, look at this sorting program! I can't believe my circuits!\n\n");

    srand(time(NULL));

    int num_elements = 10;
    int arr[num_elements];
    int i, j, temp;

    printf("I'm going to generate an array of random numbers and sort them for you. Hold on tight!\n");

    // Generate array of 10 random integers between 1 and 100
    for (i = 0; i < num_elements; i++) {
        arr[i] = rand() % 100 + 1;
    }

    printf("Okay, done generating. Here's the random array: \n");

    // Print unsorted array
    for (i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }

    // Bubble Sort
    printf("\n\nNow, let's sort it using the Bubble Sort algorithm. Get ready for this!\n");

    for (i = 0; i < num_elements-1; i++) {
        for (j = 0; j < num_elements-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Whoa! We did it! Here's the sorted array: \n");

    // Print sorted array
    for (i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }

    // Merge Sort
    printf("\n\nBut wait, there's more! Let's use the Merge Sort algorithm to sort the array again. This is crazy!\n\n");

    mergeSort(arr, 0, num_elements-1);

    printf("OMG, it worked! Here's the Merge Sorted array: \n");

    // Print Merge Sorted array
    for (i = 0; i < num_elements; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l+(r-l)/2;

        // Divide and Conquer
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        // Merge subarrays
        merge(arr, l, m, r);
    }
}