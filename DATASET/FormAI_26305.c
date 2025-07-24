//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>

/* A visionary C arithmetic example program */

int main() {
    // Declare two variables to hold numbers
    int a = 5;
    int b = 3;
  
    // Declare a variable to hold the result
    int result = 0;

    // Use a for loop to iterate 10 times
    for(int i = 1; i <= 10; i++) {
        // Check if i is odd or even
        if(i % 2 == 0) {
            // If i is even, subtract b from a
            result = a - b;
            printf("%d - %d = %d\n", a, b, result);
        } else {
            // If i is odd, add b to a
            result = a + b;
            printf("%d + %d = %d\n", a, b, result);
        }
      
        // Assign the result to a
        a = result;
    }
  
    return 0;
}