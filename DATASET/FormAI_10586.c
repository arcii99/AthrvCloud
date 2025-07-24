//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Bucket Sort implementation function
void bucket_sort(float arr[], int n) {
    // create array of buckets
    int i, j, count[n];
    float bucket[n][n], temp;

    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    // distribute elements into respective buckets
    for (i = 0; i < n; i++) {
        temp = arr[i];
        bucket[(int)(temp * n)][count[(int)(temp * n)]] = temp;
        count[(int)(temp * n)]++;
    }

    // sort each bucket and place into array
    int k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[k] = bucket[i][j];
            k++;
        }
    }
}

int main() {
    int i, n;
    float arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (0 to 1.0): ", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}