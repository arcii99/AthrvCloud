//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: puzzling
#include <stdio.h>

int main() {
    
    int arr[50], n, i;
    
    // Initializing all array elements to 0
    for (i = 0; i < 50; i++) {
        arr[i] = 0;
    }
    
    // Reading input from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Boundary condition check
    if (n <= 0 || n >= 50) {
        printf("Invalid input.\n");
        return 0;
    }
    
    // Reading n numbers
    printf("Enter the %d elements: ", n);
    for (i = 0; i < n; i++) {
       scanf("%d", &arr[i]);
    }
    
    // Sanitizing input by removing duplicate elements
    int j, k;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n;) {
            if (arr[j] == arr[i]) {
                for (k = j; k < n; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
            } 
            else {
                j++;
            }
        }
    }
    
    // Printing sanitized input
    printf("The sanitized input is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}