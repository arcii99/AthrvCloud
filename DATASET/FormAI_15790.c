//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Custom struct to hold multiple variables
typedef struct {
    int data;
    char name[20];
} Data;

void bucketSort(Data arr[], int n, int maxVal) {
    int i, j;
    Data* bucket[SIZE];

    // Allocate memory for each bucket
    for(i=0; i<SIZE; i++) {
        bucket[i] = (Data*)malloc(n * sizeof(Data));
    }

    // Distribute data into buckets
    for(i=0; i<n; i++) {
        int index = (((float)arr[i].data / maxVal) * (SIZE-1));
        bucket[index][i] = arr[i];
    }

    // Sort the individual buckets
    for(i=0; i<SIZE; i++) {
        Data* temp = bucket[i];
        for(j=1; j<n; j++) {
            int k = j;
            while(k>0 && temp[k-1].data>temp[k].data) {
                Data t = temp[k-1];
                temp[k-1] = temp[k];
                temp[k] = t;
                k--;
            }
        }
    }

    // Concatenate the sorted buckets
    int index = 0;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<n; j++) {
            if(bucket[i][j].data != 0) {
                arr[index] = bucket[i][j];
                index++;
            }
        }
    }

    // Free memory used by buckets
    for(i=0; i<SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    Data arr[] = {{21, "Alice"}, {5, "Bob"}, {32, "Charlie"}, {44, "David"}, {19, "Emma"},
                  {8, "Frank"}, {27, "Grace"}, {14, "Henry"}, {30, "Isaac"}, {11, "John"}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxVal = 44;

    printf("Before sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d - %s\n", arr[i].data, arr[i].name);
    }

    bucketSort(arr, n, maxVal);

    printf("\nAfter sorting:\n");
    for(int i=0; i<n; i++) {
        printf("%d - %s\n", arr[i].data, arr[i].name);
    }

    return 0;
}