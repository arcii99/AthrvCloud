//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to implement Bucket Sort
void bucketSort(float arr[], int n) {

    // Create n buckets
    int i, j;
    int count[n];
    for(i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Store count of elements in each bucket
    for(i = 0; i < n; i++) {
        count[(int)(n * arr[i])]++; 
    }

    // Sort elements in each bucket using insertion sort
    for(i = 0; i < n; i++) {
        int k = (int)(n * arr[i]);
        float temp_bucket[k];
        float val = arr[i];
        int temp_cnt = 0;

        // add element to the correct position in the bucket
        while(temp_cnt < count[k]) {
            if(val < temp_bucket[temp_cnt]) {
                float temp = temp_bucket[temp_cnt];
                temp_bucket[temp_cnt] = val;
                val = temp;
            }
            temp_cnt++;
        }
        temp_bucket[count[k]] = val;
        count[k]++;

        // Combine all the sorted buckets
        int cnt = 0;
        for(j = 0; j < n; j++) {
            while(count[j] > 0) {
                arr[cnt] = (float)j / n;
                cnt++;
                count[j]--;
            }
        }
    }
}

// Driver program to test above function
int main() {

    float arr[] = {0.12, 0.05, 0.67, 0.91, 0.1, 0.5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for(int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
    return 0;
}