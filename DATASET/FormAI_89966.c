//FormAI DATASET v1.0 Category: Arithmetic ; Style: romantic
#include <stdio.h>

int main() {
    // Initializing the variables
    int a = 10, b = 20;
    int temp;

    // Swapping their values using arithmetic operations
    temp = a + b;
    a = temp - a;
    b = temp - b;

    // Displaying the swapped values as a romantic message
    printf("My love, I have swapped the values of our hearts:\n");
    printf("Your heart is now beating for me with intensity %d\n", a);
    printf("And my heart is now beating for you with intensity %d\n", b);

    return 0;
}