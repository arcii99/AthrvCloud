//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: energetic
#include <stdio.h>
#define MAX_ARRAY_SIZE 1000000

int main() {

    int arr[MAX_ARRAY_SIZE];

    // Generate random values for the array
    for(int i=0; i<MAX_ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Calculate the average value of the array
    int sum = 0;
    for(int i=0; i<MAX_ARRAY_SIZE; i++) {
        sum += arr[i];
    }
    double avg = (double)sum / MAX_ARRAY_SIZE;
    printf("Average value of the array: %lf\n", avg);

    // Find the minimum and maximum value of the array
    int min = arr[0];
    int max = arr[0];
    for(int i=1; i<MAX_ARRAY_SIZE; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Minimum value of the array: %d\n", min);
    printf("Maximum value of the array: %d\n", max);

    // Sort the array using bubble sort algorithm
    for(int i=0; i<MAX_ARRAY_SIZE-1; i++) {
        for(int j=0; j<MAX_ARRAY_SIZE-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for(int i=0; i<MAX_ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}