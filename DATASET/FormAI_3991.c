//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complete
#include <stdio.h>

// DSP function to calculate the moving average of an array
void moving_average(int arr[], int arr_len, int window_size, float output[]) {
    int i, j;
    float sum;
    
    // loop through each window
    for(i=0; i<=arr_len-window_size; i++) {
        sum = 0;
        
        // loop through each value in the window and calculate the sum
        for(j=i; j<i+window_size; j++) {
            sum += arr[j];
        }
        
        // divide the sum by the window size and store the result in the output array
        output[i] = sum/window_size;
    }
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arr_len = sizeof(arr)/sizeof(arr[0]);
    int window_size = 3;
    float output[arr_len-window_size+1];
    int i;
    
    // calculate the moving average of the array using a window size of 3
    moving_average(arr, arr_len, window_size, output);
    
    // print the input array and the output array
    printf("Input array: ");
    for(i=0; i<arr_len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Moving average output array (window size = %d): ", window_size);
    for(i=0; i<arr_len-window_size+1; i++) {
        printf("%.2f ", output[i]);
    }
    printf("\n");
    
    return 0;
}