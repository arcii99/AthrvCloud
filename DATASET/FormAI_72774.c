//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

// Function to print the surrealistic list
void print(int arr[], int n) {
    for(int i=0;i<n;i++) {
        printf("%d , ",arr[i]);
    }
    printf("\n");
}

// Function to implement Surrealistic Bucket Sort
void surrealisticBucketSort(int arr[], int n) {

    // Array of surrealistic buckets
    int buckets[7][n];

    // Counter variables for each bucket
    int counter[7] = {0};

    // Fill the surrealistic buckets with elements from the original array
    for(int i=0;i<n;i++) {
        if(arr[i]<0) {
            buckets[0][counter[0]] = arr[i];
            counter[0]++;
        }
        else if(arr[i]==0) {
            buckets[1][counter[1]] = arr[i];
            counter[1]++;
        }
        else if(arr[i]<=10) {
            buckets[2][counter[2]] = arr[i];
            counter[2]++;
        }
        else if(arr[i]<=100) {
            buckets[3][counter[3]] = arr[i];
            counter[3]++;
        }
        else if(arr[i]<=1000) {
            buckets[4][counter[4]] = arr[i];
            counter[4]++;
        }
        else if(arr[i]<=10000) {
            buckets[5][counter[5]] = arr[i];
            counter[5]++;
        }
        else {
            buckets[6][counter[6]] = arr[i];
            counter[6]++;
        }
    }

    // Sort the surrealistic buckets using Bubble Sort
    for(int i=0;i<7;i++) {
        for(int j=0;j<counter[i]-1;j++) {
            for(int k=0;k<counter[i]-j-1;k++) {
                if(buckets[i][k]>buckets[i][k+1]) {
                    int temp = buckets[i][k];
                    buckets[i][k] = buckets[i][k+1];
                    buckets[i][k+1] = temp;
                }
            }
        }
    }

    // Merge the surrealistic buckets back into the original array
    int index = 0;
    for(int i=0;i<7;i++) {
        for(int j=0;j<counter[i];j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main() {
    printf("Surrealistic Bucket Sort Implementation\n\n");

    // Initialize the original array with surrealistic elements
    int arr[10] = {1, -2, 0, 5, 9, 100000, -10, 10, 100, 1000};

    printf("Original List:\n");
    print(arr, 10);

    surrealisticBucketSort(arr, 10);

    printf("\nSurrealistic Sorted List:\n");
    print(arr, 10);

    return 0;
}