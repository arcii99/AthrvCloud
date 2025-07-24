//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: distributed
#include <stdio.h>

#define BUCKETSIZE 10

void bucketSort(int array[], int n) {
    int i, j;
    int bucket[BUCKETSIZE];

    for(i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    for(i = 0; i < n; i++) {
        bucket[array[i]]++;
    }

    for(i = 0, j = 0; j < BUCKETSIZE; j++) {
        for(; bucket[j] > 0; bucket[j]--) {
            array[i++] = j;
        }
    }
}

int main() {
    int i, n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d elements to be sorted:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    bucketSort(array, n);

    printf("Sorted array is:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}