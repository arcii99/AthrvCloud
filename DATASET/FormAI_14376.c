//FormAI DATASET v1.0 Category: Data mining ; Style: accurate
#include<stdio.h>

// Function to calculate the maximum value of an array
int getMax(int arr[], int n){
    int max = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to calculate the minimum value of an array
int getMin(int arr[], int n){
    int min = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main(){
    int n; // Number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n]; // Array to store the elements
    printf("Enter the elements in the array: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    int max = getMax(arr, n); // Calculate the maximum value
    int min = getMin(arr, n); // Calculate the minimum value
    
    printf("Maximum value in the array: %d\n", max);
    printf("Minimum value in the array: %d\n", min);
    
    return 0;
}