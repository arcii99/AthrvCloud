//FormAI DATASET v1.0 Category: Data mining ; Style: modular
#include<stdio.h>
#include<stdlib.h>

// Function to calculate the average of an integer array
float calculate_average(int arr[], int size){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += arr[i];
    }
    float average = (float)sum / size;
    return average;
}

// Function to find the maximum value in an integer array
int find_maximum(int arr[], int size){
    int max = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum value in an integer array
int find_minimum(int arr[], int size){
    int min = arr[0];
    for(int i=1; i<size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

// Main function
int main(){

    // Input integer array
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr)/sizeof(arr[0]);

    // Calculate the average and print it
    float average = calculate_average(arr, size);
    printf("Average value is: %f \n", average);

    // Find the maximum value and print it
    int maximum = find_maximum(arr, size);
    printf("Maximum value is: %d \n", maximum);

    // Find the minimum value and print it
    int minimum = find_minimum(arr, size);
    printf("Minimum value is: %d \n", minimum);

    return 0;
}