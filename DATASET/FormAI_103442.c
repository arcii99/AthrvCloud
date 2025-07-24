//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scientific
/*==========================================================
 *   File: perf_component.c
 *   
 *   Brief: This program demonstrates a performance-critical 
 *          component in C. It generates a set of random integers 
 *          and calculates the largest and smallest number, median, 
 *          and average of the set using different algorithms. 
 *
 *   Author: [Your_Name]
 *
 *   Date: [Date]
 *
 *=========================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000   // Define size of array
#define MAX_INT 10000       // Define maximum value of integers to generate

// Function to generate a set of random integers
void generateRandomIntegers(int arr[]) {
    for (int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = rand() % MAX_INT;      // Generate a random integer between 0 and MAX_INT
    }
}

// Function to find the largest number in the array using simple linear search
int findLargestLinearSearch(int arr[]) {
    int largest = arr[0];
    for (int i=1; i<ARRAY_SIZE; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

// Function to find the smallest number in the array using simple linear search
int findSmallestLinearSearch(int arr[]) {
    int smallest = arr[0];
    for (int i=1; i<ARRAY_SIZE; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

// Function to find the median of an array using insertion sort
double findMedianInsertionSort(int arr[]) {
    for (int i=1; i<ARRAY_SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
    double median;
    if (ARRAY_SIZE%2 == 0) {
        median = (double)(arr[ARRAY_SIZE/2] + arr[(ARRAY_SIZE/2)-1])/2;
    } else {
        median = (double)arr[(ARRAY_SIZE-1)/2];
    }
    return median;
}

// Function to find the median of an array using quick sort
double findMedianQuickSort(int arr[], int start, int end) {
    if (start < end) {
        int pivot = arr[end];     // Select the pivot as the last element
        int i = start - 1;
        for (int j=start; j<=end-1; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = temp;
        int pivotIndex = i+1;
        double median;
        if (pivotIndex == ARRAY_SIZE/2) {
            median = (double)pivot;
        } else if (pivotIndex < ARRAY_SIZE/2) {
            median = findMedianQuickSort(arr, pivotIndex+1, end);
        } else {
            median = findMedianQuickSort(arr, start, pivotIndex-1);
        }
        return median;
    }
}

// Function to calculate the average of an array
double calculateAverage(int arr[]) {
    double sum = 0.0;
    for (int i=0; i<ARRAY_SIZE; i++) {
        sum += arr[i];
    }
    return (sum / (double)ARRAY_SIZE);
}

int main() {
    int arr[ARRAY_SIZE];
    srand(time(0));     // Seed the random number generator

    // Generate a set of random integers
    generateRandomIntegers(arr);

    // Find the largest number in the array using simple linear search
    int largest = findLargestLinearSearch(arr);
    printf("Largest Number: %d\n", largest);

    // Find the smallest number in the array using simple linear search
    int smallest = findSmallestLinearSearch(arr);
    printf("Smallest Number: %d\n", smallest);

    // Find the median of the array using insertion sort
    double median1 = findMedianInsertionSort(arr);
    printf("Median (Insertion Sort): %f\n", median1);

    // Find the median of the array using quick sort
    double median2 = findMedianQuickSort(arr, 0, ARRAY_SIZE-1);
    printf("Median (Quick Sort): %f\n", median2);

    // Calculate the average of the array
    double average = calculateAverage(arr);
    printf("Average: %f\n", average);

    return 0;
}