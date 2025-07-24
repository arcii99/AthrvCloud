//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    const char *message = "Hello, world!\n"; // Declare a constant string
    printf("%s", message); // Print the string to stdout
    for (int i = 0; i < 10; i++) { // Iterate from 0 to 9
        printf("i is now %d\n", i); // Print the current value of i
    }
    int x = 5; // Declare an integer
    if (x == 5) { // Check if x equals 5
        printf("x is 5\n"); // Print a message
    } else { // If x is not 5
        printf("x is not 5\n"); // Print a different message
    }
    int y = 10; // Declare another integer
    int z = x + y; // Add x and y and store the result in z
    printf("z is %d\n", z); // Print the value of z
    return 0; // Return 0 to indicate success
}