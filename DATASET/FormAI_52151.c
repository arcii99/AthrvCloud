//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100 // Define the size of the array

// Function that generates random data
void generateData(int arr[], int size) {
    int i;

    // Use current time as seed for random generator
    srand(time(0));

    // Generate random data
    for(i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
}

// Function that finds the median of the array
int findMedian(int arr[], int size) {
    int i, j, temp;

    // Sort the array in ascending order using bubble sort
    for(i = 0; i < size; i++) {
        for(j = 0; j < size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Calculate the median
    if(size % 2 == 0) {
        return (arr[(size/2)-1] + arr[size/2]) / 2;
    } else {
        return arr[size/2];
    }
}

// Function that finds the mode of the array
int findMode(int arr[], int size) {
    int i, j;
    int value, count, maxCount = 0, mode = 0;

    // Count the number of occurrences of each value
    for(i = 0; i < size; i++) {
        value = arr[i];
        count = 0;
        for(j = 0; j < size; j++) {
            if(arr[j] == value) {
                count++;
            }
        }
        // Update the mode if the current count is higher than the previous max count
        if(count > maxCount) {
            maxCount = count;
            mode = value;
        }
    }

    return mode;
}

int main() {
    int data[ARRAY_SIZE];
    int median, mode;

    // Generate random data
    generateData(data, ARRAY_SIZE);

    // Find the median and mode of the array
    median = findMedian(data, ARRAY_SIZE);
    mode = findMode(data, ARRAY_SIZE);

    // Print the results
    printf("Median: %d\n", median);
    printf("Mode: %d\n", mode);

    return 0;
}