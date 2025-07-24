//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include<stdio.h>

//function to get the checksum
int getChecksum(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    int checksum = sum % 256;
    return checksum;
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int checksum = getChecksum(arr, n);
    
    printf("Checksum in decimal: %d\n", checksum);
    printf("Checksum in hexadecimal: %x\n", checksum);
    
    return 0;
}