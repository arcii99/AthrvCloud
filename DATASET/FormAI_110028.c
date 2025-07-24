//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Donald Knuth
// Donald Knuth-style Bitwise Operations Example Program
#include <stdio.h>

// Function to check if a number is a power of two or not
int is_power_of_two(int num) {
    return num && !(num & (num - 1));
}

// Function to print binary representation of a number
void print_binary(unsigned int num) {
    int i;
    for (i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to clear the rightmost set bit in a number
int clear_rightmost_set_bit(int num) {
    return num & (num - 1);
}

// Function to count the number of set bits in a number
int count_set_bits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);
        count++;
    }
    return count;
}

// Function to swap two numbers using bitwise XOR
void swap_numbers(int *num1, int *num2) {
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
}

int main() {
    int num = 10;

    printf("Is %d power of two? %d\n", num, is_power_of_two(num));

    printf("Binary representation of %d is ", num);
    print_binary(num);

    printf("Clearing the rightmost set bit in %d gives %d\n", num, clear_rightmost_set_bit(num));

    printf("The number of set bits in %d is %d\n", num, count_set_bits(num));

    int num1 = 25, num2 = 10;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap_numbers(&num1, &num2);
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}