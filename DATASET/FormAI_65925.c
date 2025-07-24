//FormAI DATASET v1.0 Category: Bitwise operations ; Style: visionary
#include <stdio.h>

/* Visionary Bitwise Operations Program */

/* This program demonstrates the power of bitwise operations in creating
   complex and imaginative functions with only a few lines of code. It was designed
   to showcase the beauty and elegance of C programming, and to inspire other 
   programmers to explore the full potential of this amazing language. */


/* Function to reverse a number using bitwise XOR operation */
int reverse_number(int num){
    int rev = 0;
    while (num > 0){
        rev = rev << 1;
        if (num & 1){
            rev = rev ^ 1;
        }
        num = num >> 1;
    }
    return rev;
}

/* Function to count the number of set bits using bitwise AND operation */
int count_set_bits(int num){
    int count = 0;
    while (num > 0){
        if (num & 1){
            count++;
        }
        num = num >> 1;
    }
    return count;
}

/* Function to swap two numbers using bitwise XOR operation */
void swap_numbers(int *a, int *b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/* Function to check if a number is power of two using bitwise AND operation */
int is_power_of_two(int num){
    return (num & (num - 1)) == 0;
}

/* Function to calculate the absolute value of a number using bitwise operations */
int abs_value(int num){
    int mask = num >> 31;
    return (num + mask) ^ mask;
}

int main(){
    int num1 = 10, num2 = 20;
    printf("Original values: num1 = %d, num2 = %d\n", num1, num2);
    swap_numbers(&num1, &num2);
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    int num3 = 15;
    printf("Reverse of %d is %d\n", num3, reverse_number(num3));
    printf("%d has %d set bits\n", num3, count_set_bits(num3));

    int num4 = 32;
    printf("%d is %s power of two\n", num4, is_power_of_two(num4) ? "a" : "not a");

    int num5 = -25;
    printf("Absolute value of %d is %d\n", num5, abs_value(num5));

    return 0;
}