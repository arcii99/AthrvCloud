//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include<stdio.h>

//Function to calculate the checksum
int calculate_checksum(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum;
}

int main() {
    int arr[100], size, checksum;
    
    //Taking input from user
    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    printf("Enter the elements: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    //Calculating the checksum
    checksum = calculate_checksum(arr, size);
    
    //Displaying the result
    printf("The checksum value is: %d", checksum);
    
    return 0;
}