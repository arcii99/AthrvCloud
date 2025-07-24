//FormAI DATASET v1.0 Category: Bitwise operations ; Style: futuristic
/* Welcome to the Matrix */

#include <stdio.h>
#include <stdlib.h>

/* Function to set a single bit at a particular position */

int set_bit(int num, int pos) {
    int mask = 1 << pos;
    return num | mask;
}

/* Function to clear a single bit at a particular position */

int clear_bit(int num, int pos) {
    int mask = ~(1 << pos);
    return num & mask;
}

/* Function to toggle a single bit at a particular position */

int toggle_bit(int num, int pos) {
    int mask = 1 << pos;
    return num ^ mask;
}

int main() {
    int a = 45; // 0b00101101
    int b = 23; // 0b00010111

    printf("Welcome to the Matrix!\n");
    printf("The value of a is: %d\n", a);
    printf("The value of b is: %d\n", b);

    int c = set_bit(a, 2); // Set bit 2 in a
    printf("Set bit 2 in a: %d\n", c);

    int d = clear_bit(b, 4); // Clear bit 4 in b
    printf("Clear bit 4 in b: %d\n", d);

    int e = toggle_bit(a, 5); // Toggle bit 5 in a
    printf("Toggle bit 5 in a: %d\n", e);

    return EXIT_SUCCESS;
}