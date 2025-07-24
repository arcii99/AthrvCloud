//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

// Function to calculate Checksum
int checksum(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

// Main function
int main(){
    int arr[] = {2, 7, 8, 1, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int chk_sum = checksum(arr, n);  // Calculate Cheksum

    printf("Input Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Checksum: %d\n", chk_sum);

    return 0;
}