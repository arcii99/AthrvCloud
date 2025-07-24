//FormAI DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>

// Function to calculate mean
float mean(int arr[], int n){
    float sum = 0;
    for(int i=0; i<n; ++i){
        sum += arr[i];
    }
    return sum/n;
}

// Function to calculate variance
float variance(int arr[], int n){
    float m = mean(arr, n);
    float sum = 0;
    for(int i=0; i<n; ++i){
        sum += (arr[i]-m)*(arr[i]-m);
    }
    return sum/n;
}

// Function to calculate standard deviation
float std_dev(int arr[], int n){
    float var = variance(arr, n);
    return sqrt(var);
}

int main(){
    int arr[10] = {2, 5, 3, -6, 8, 10, 12, -4, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Data:\n");
    for(int i=0; i<n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Calculate mean
    float mean_val = mean(arr, n);
    printf("Mean: %f\n", mean_val);
    
    // Calculate variance
    float var_val = variance(arr, n);
    printf("Variance: %f\n", var_val);
    
    // Calculate standard deviation
    float std_dev_val = std_dev(arr, n);
    printf("Standard Deviation: %f\n", std_dev_val);
    
    return 0;
}