//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>

// Function to find the happiest number in an array
int findHappiestNumber(int arr[], int size) {

    int happiest_num = arr[0]; // Set the first number as the happiest for now

    // Loop through the array to find the happiest number
    for(int i = 1; i < size; i++) {
        // If the current number is happier than the happiest number so far, update the happiest number
        if(arr[i] > happiest_num) {
            happiest_num = arr[i];
        }
    }

    // Return the happiest number
    return happiest_num;
}

int main() {
    
    int arr[] = {1, 5, 10, 3, 7, 9, 2, 8, 4, 6}; // Array of numbers
    int size = sizeof(arr) / sizeof(arr[0]); // Get the size of the array

    // Call the function to find the happiest number
    int happiest_num = findHappiestNumber(arr, size);

    // Cheerful output to let the user know the happiest number
    printf("Yay! The happiest number is %d! :D", happiest_num);

    return 0;
}