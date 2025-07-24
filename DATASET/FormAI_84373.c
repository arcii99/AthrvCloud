//FormAI DATASET v1.0 Category: Math exercise ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate the average of an array of integers
double calculate_average(int arr[], int len) {
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum += arr[i];
    }
    return (double)sum / len;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Declare an array of integers with a random length between 10 and 20
    int len = rand() % 11 + 10;
    int arr[len];
    
    // Fill the array with random integers between 1 and 100
    printf("The initial array is:\n");
    for(int i = 0; i < len; i++) {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Calculate the average of the array
    double average = calculate_average(arr, len);
    printf("The average of the array is: %f\n\n", average);

    // Initialize variables to find the smallest and largest numbers in the array
    int smallest = arr[0];
    int largest = arr[0];
    
    // Loop through the array to find the smallest and largest numbers
    for(int i = 1; i < len; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    
    // Print the smallest and largest numbers in the array
    printf("The smallest number in the array is: %d\n", smallest);
    printf("The largest number in the array is: %d\n\n", largest);

    // Initialize variables to store the number of even and odd numbers in the array
    int even_count = 0;
    int odd_count = 0;
    
    // Loop through the array to count the number of even and odd numbers
    for(int i = 0; i < len; i++) {
        if(arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    
    // Print the number of even and odd numbers in the array
    printf("The number of even numbers in the array is: %d\n", even_count);
    printf("The number of odd numbers in the array is: %d\n\n", odd_count);

    // Initialize variables to store the sum and product of the elements in the array
    int sum = 0;
    int product = 1;
    
    // Loop through the array to calculate the sum and product of the elements
    for(int i = 0; i < len; i++) {
        sum += arr[i];
        product *= arr[i];
    }
    
    // Print the sum and product of the elements in the array
    printf("The sum of the elements in the array is: %d\n", sum);
    printf("The product of the elements in the array is: %d\n\n", product);

    // Initialize variables to store the index of the largest and smallest numbers in the array
    int smallest_index = 0;
    int largest_index = 0;

    // Loop through the array to find the index of the smallest and largest numbers
    for(int i = 1; i < len; i++) {
        if(arr[i] < arr[smallest_index]) {
            smallest_index = i;
        }
        if(arr[i] > arr[largest_index]) {
            largest_index = i;
        }
    }

    // Print the index of the smallest and largest numbers in the array
    printf("The index of the smallest number in the array is: %d\n", smallest_index);
    printf("The index of the largest number in the array is: %d\n\n", largest_index);

    // Initialize variables to store the sorted array and a temporary variable for swapping elements
    int sorted_arr[len];
    int temp;
    
    // Copy the array to the sorted array
    for(int i = 0; i < len; i++) {
        sorted_arr[i] = arr[i];
    }

    // Implement bubble sort algorithm to sort the array in ascending order
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - i - 1; j++) {
            if(sorted_arr[j] > sorted_arr[j+1]) {
                temp = sorted_arr[j];
                sorted_arr[j] = sorted_arr[j+1];
                sorted_arr[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("The sorted array is:\n");
    for(int i = 0; i < len; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n\n");

    // Return 0 to indicate successful completion of program
    return 0;
}