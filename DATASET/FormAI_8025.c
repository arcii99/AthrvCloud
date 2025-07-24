//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to generate random numbers from 0 to 9999
void generateNumbers(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

// the main function
int main() {
    int arr[10];
    int bucket[10][10] = {0};
    int bucket_count[10] = {0};

    // generate random numbers and print them
    generateNumbers(arr, 10);
    printf("The original array: ");
    printArray(arr, 10);

    // get the maximum number in the array
    int max = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // get the digit count of the maximum number
    int digit_count = 0;
    while (max > 0) {
        max = max / 10;
        digit_count++;
    }

    // perform bucket sort for each digit
    for (int i = 1; i <= digit_count; i++) {

        // place numbers into their respective buckets
        for (int j = 0; j < 10; j++) {
            int digit = (arr[j] / (int)pow(10, i-1)) % 10;
            bucket[digit][bucket_count[digit]] = arr[j];
            bucket_count[digit]++;
        }

        // put numbers back into the array in sorted order
        int index = 0;
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < bucket_count[j]; k++) {
                arr[index++] = bucket[j][k];
            }
        }

        // reset the bucket counts to 0
        for (int j = 0; j < 10; j++) {
            bucket_count[j] = 0;
        }

        // print the current state of the array
        printf("After %dth digit pass: ", i);
        printArray(arr, 10);
    }

    // print the final sorted array
    printf("The sorted array: ");
    printArray(arr, 10);

    return 0;
}