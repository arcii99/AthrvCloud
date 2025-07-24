//FormAI DATASET v1.0 Category: Data mining ; Style: enthusiastic
#include <stdio.h>

/* Data mining example program */

int main() {
    // Declare and initialize an array of integers
    int data[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    
    // Declare variables for loop iteration and minimum value
    int i, min = data[0];
    
    // Iterate through array to find minimum value
    for (i = 1; i < 10; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    
    // Output minimum value to console
    printf("The minimum value in the data set is: %d", min);
    
    return 0;
}