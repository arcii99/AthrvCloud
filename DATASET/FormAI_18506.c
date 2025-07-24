//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>

// function to find the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i=1; i<n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// function to perform counting sort based on a digit position
void countSort(int arr[], int n, int exp) {
    int output[n]; // output array to store sorted elements
    int count[10] = {0}; // count array to count occurrences of each digit

    // count occurrences of each digit
    for (int i=0; i<n; i++) {
        count[(arr[i]/exp)%10]++;
    }

    // update count array to have actual positions of digits in sorted array
    for (int i=1; i<10; i++) {
        count[i] += count[i-1];
    }

    // place elements in output array based on digit position
    for (int i=n-1; i>=0; i--) {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    // copy output array back to original array
    for (int i=0; i<n; i++) {
        arr[i] = output[i];
    }
}

// function to perform radix sort on an array
void radixSort(int arr[], int n) {
    // find the maximum value in the array
    int max = getMax(arr, n);

    // perform counting sort for each digit position (starting from least significant to most significant)
    for (int exp=1; max/exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);
    printf("Sorted array: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}