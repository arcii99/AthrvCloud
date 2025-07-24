//FormAI DATASET v1.0 Category: Sorting ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    printf("Ready to sort some numbers? Let's do this!\n");
    srand(time(0)); // Setting the seed using current system time for generating random numbers
    int n = 10; // Number of elements in array
    int arr[n]; // Declaring an array of n elements
    printf("Unsorted Array: ");
    for(int i=0;i<n;i++){
        arr[i] = rand() % 50; // Generating random numbers between 0 and 50 and assigning to array elements
        printf("%d ",arr[i]); // Printing the unsorted array
    }
    printf("\nLet's sort this array using Bubble Sort Algorithm!\n");
    
    // Bubble Sort Algorithm
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                // Swapping the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]); // Printing the sorted array
    }
    printf("\nTa-da! Our array has been sorted using Bubble Sort Algorithm.\n");
    return 0;
}