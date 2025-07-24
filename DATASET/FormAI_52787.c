//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>

int checksum(int *arr, int n) {
    if(n == 0){
        return 0;
    } else {
        return arr[n-1] + checksum(arr, n-1);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    int result = checksum(arr, n);
    printf("The checksum of the array is: %d", result);
    
    return 0;
}