//FormAI DATASET v1.0 Category: Benchmarking ; Style: multivariable
#include<stdio.h>
#include<time.h>

// Define the size of the array
#define ARRAY_SIZE 10000

// Function to initialize the array with random numbers
void initialize_array(int arr[]) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }
}

// Function to display the array elements
void display_array(int arr[]) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bubble sort on the array
void bubble_sort(int arr[]) {
    int temp;
    for(int i=0; i<ARRAY_SIZE-1; i++) {
        for(int j=i+1; j<ARRAY_SIZE; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to perform insertion sort on the array
void insertion_sort(int arr[]) {
    int key, j;
    for(int i=1; i<ARRAY_SIZE; i++) {
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

// Main function
int main() {
    // Declare and initialize the array
    int arr[ARRAY_SIZE];
    initialize_array(arr);
    
    // Display the unsorted array
    printf("Unsorted array:\n");
    display_array(arr);
    
    // Perform bubble sort on the array and display the sorted array
    clock_t t1 = clock();
    bubble_sort(arr);
    clock_t t2 = clock();
    double time_taken_bubble = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Sorted array using bubble sort:\n");
    display_array(arr);
    printf("Time taken by bubble sort: %lf seconds\n", time_taken_bubble);
    
    // Perform insertion sort on the array and display the sorted array
    initialize_array(arr);
    printf("Unsorted array:\n");
    display_array(arr);
    t1 = clock();
    insertion_sort(arr);
    t2 = clock();
    double time_taken_insertion = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Sorted array using insertion sort:\n");
    display_array(arr);
    printf("Time taken by insertion sort: %lf seconds\n", time_taken_insertion);
    
    return 0;
}