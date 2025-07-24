//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000

void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main()
{
    int choice, i;
    int arr[ARRAY_SIZE];
    
    // generate random integers for array
    srand(time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand();
    }
    
    // prompt user to choose sorting algorithm
    printf("Choose a sorting algorithm:\n");
    printf("1. Bubble sort\n");
    printf("2. Selection sort\n");
    printf("3. Insertion sort\n");
    
    scanf("%d", &choice);
    
    // call the chosen sorting algorithm
    switch(choice) {
        case 1: bubbleSort(arr, ARRAY_SIZE);
            printf("Array sorted using bubble sort.\n");
            break;
        case 2: selectionSort(arr, ARRAY_SIZE);
            printf("Array sorted using selection sort.\n");
            break;
        case 3: insertionSort(arr, ARRAY_SIZE);
            printf("Array sorted using insertion sort.\n");
            break;
        default: printf("Invalid choice!\n");
    }
    
    // display sorted array
    printf("Sorted array:\n");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

// Bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection sort
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;
    for(i = 0; i < n-1; i++) {
        minIndex = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Insertion sort
void insertionSort(int arr[], int n)
{
    int i, j, key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}