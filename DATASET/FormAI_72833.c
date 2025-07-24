//FormAI DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>

// function to calculate sum of array elements
int getSum(int arr[], int n) {
    int i, sum = 0;
    for(i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// function to calculate average of array elements
float getAverage(int arr[], int n) {
    int sum = getSum(arr, n);
    return (float) sum / n;
}

int main() {
    int n, i, arr[100];
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    float average = getAverage(arr, n);
    
    printf("Average of array elements: %f\n", average);
    
    return 0;
}