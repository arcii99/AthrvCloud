//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to get a random number between two limits
int get_random_number(int min, int max) {
    srand(time(NULL)); // Seed the random number generator with the current time
    return (rand() % (max - min + 1)) + min; // Generate a random number in the given range
}

// Function to loop through the elements of an array and print them
void print_array_elements(int arr[], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Define an array with 10 elements
    int arr[10];
    
    // Get 10 random numbers and assign them to the array
    for(int i=0; i<10; i++) {
        arr[i] = get_random_number(1, 100);
    }
    
    // Print the array elements
    printf("Array before sorting: ");
    print_array_elements(arr, 10);
    
    // Sort the array using bubble sort algorithm
    int temp;
    for(int i=0; i<10; i++) {
        for(int j=0; j<9-i; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    // Print the sorted array elements
    printf("Array after sorting: ");
    print_array_elements(arr, 10);
    
    return 0;
}