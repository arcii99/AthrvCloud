//FormAI DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>

int main() {
    int data[10] = {1, 3, 5, 2, 6, 4, 9, 8, 7, 10}; // example dataset
    int n = 10; // number of elements in dataset
    int i, j, temp;

    // print unsorted dataset
    printf("Unsorted dataset: ");
    for(i=0; i<n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // bubble sort algorithm to sort dataset
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(data[j] > data[j+1]) {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    // print sorted dataset
    printf("Sorted dataset: ");
    for(i=0; i<n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // calculate mean of dataset
    float mean = 0;
    for(i=0; i<n; i++) {
        mean += data[i];
    }
    mean /= n;
    printf("Mean: %f\n", mean);

    // calculate median of dataset
    float median = 0;
    if(n % 2 == 0) {
        median = (data[n/2-1] + data[n/2]) / 2.0;
    } else {
        median = data[n/2];
    }
    printf("Median: %f\n", median);

    // calculate mode of dataset
    int mode = 0;
    int count = 0;
    int max_count = 0;
    for(i=0; i<n; i++) {
        count = 0;
        for(j=0; j<n; j++) {
            if(data[j] == data[i]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            mode = data[i];
        }
    }
    printf("Mode: %d\n", mode);

    return 0;
}