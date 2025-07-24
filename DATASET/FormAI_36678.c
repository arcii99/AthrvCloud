//FormAI DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Generate random number between 0 to 255
int random_number() {
    return rand() % 256;
}

// Print integer in binary format
void print_binary(int num) {
    int mask = 1 << 7;
    for(int i = 0; i < 8; i++) {
        if(num & mask)
            printf("1");
        else
            printf("0");
        mask = mask >> 1;
    }
    printf("\n");
}

// Execute the bitwise operations asynchronously
void execute_operations(int a, int b) {
    printf("a = ");
    print_binary(a);
    printf("b = ");
    print_binary(b);

    // Asynchronous AND
    int and_result = a & b;
    printf("Asynchronous AND: ");
    print_binary(and_result);

    // Asynchronous OR
    int or_result = a | b;
    printf("Asynchronous OR: ");
    print_binary(or_result);

    // Asynchronous XOR
    int xor_result = a ^ b;
    printf("Asynchronous XOR: ");
    print_binary(xor_result);
}

int main() {
    srand(time(0));

    int a = random_number();
    int b = random_number();
    printf("Async Bitwise Operations\n");
    execute_operations(a, b);

    return 0;
}