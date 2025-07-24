//FormAI DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>

// function to find the maximum value in an array
int findMax(int arr[], int size) {
    int maxVal = arr[0]; // assume first element as maximum value
    for(int i = 1; i < size; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    
    // generate some random data
    int data[] = {36, 12, 90, 68, 20, 85, 94, 27, 61, 8};
    int dataSize = sizeof(data)/sizeof(data[0]);
    
    // print the input data
    printf("Input data: ");
    for(int i = 0; i < dataSize; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    // find the maximum value in the input data
    int maxVal = findMax(data, dataSize);
    
    // print the maximum value
    printf("Maximum value: %d\n", maxVal);
    
    return 0;
}