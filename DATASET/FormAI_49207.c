//FormAI DATASET v1.0 Category: Arithmetic ; Style: future-proof
#include <stdio.h>

int main() {
    int n = 10;
    int arr1[n], arr2[n], sum[n], diff[n], prod[n];
    
    printf("Enter %d numbers for Array 1: \n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr1[i]);
    }
    
    printf("Enter %d numbers for Array 2: \n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr2[i]);
    }
    
    // Compute sum of the two arrays
    for(int i=0; i<n; i++) {
        sum[i] = arr1[i] + arr2[i];
    }
    
    // Compute difference of the two arrays
    for(int i=0; i<n; i++) {
        diff[i] = arr1[i] - arr2[i];
    }
    
    // Compute product of the two arrays
    for(int i=0; i<n; i++) {
        prod[i] = arr1[i] * arr2[i];
    }
    
    // Print results
    printf("\n\nSum of the two arrays:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", sum[i]);
    }
    
    printf("\n\nDifference of the two arrays:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", diff[i]);
    }
    
    printf("\n\nProduct of the two arrays:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", prod[i]);
    }
    
    return 0;
}