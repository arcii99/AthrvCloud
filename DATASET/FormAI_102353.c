//FormAI DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
// Linus Torvalds inspired C Program
// This program finds the sum of first 100 even numbers

#include <stdio.h>

#define MAX_VAL 100  // Maximum value to find sum for
#define MULTIPLE 2   // The multiple of numbers to find

int main() {

    int sum = 0;
    int i;

    for (i = 1; i <= MAX_VAL; i++) {
        if ((i * MULTIPLE) % MULTIPLE == 0) {  // Check if the number is a multiple of 2 (even number)
            sum += i * MULTIPLE;   // Add up the even numbers
        }
    }

    printf("The sum of the first %d even numbers is %d\n", MAX_VAL, sum);

    return 0;
}