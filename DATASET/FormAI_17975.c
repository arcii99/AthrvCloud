//FormAI DATASET v1.0 Category: Educational ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int arr[10];
    srand(time(NULL));
  
    // Generate random numbers for array
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100;
    }
  
    // Print original array
    printf("The original array is:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
  
    // Sort array in ascending order
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
  
    // Print sorted array
    printf("\nThe sorted array is:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
  
    // Calculate average of array
    int sum = 0;
    double average;
  
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }
  
    average = (double)sum / 10;
  
    printf("\nThe average of the array is: %.2f", average);
  
    return 0;
}