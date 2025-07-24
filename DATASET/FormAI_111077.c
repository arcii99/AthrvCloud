//FormAI DATASET v1.0 Category: Educational ; Style: expert-level
#include <stdio.h>

/* This program demonstrates the use of pointers in C programming language */

/* Function prototypes */
void swap(int *a, int *b);
int add_numbers(int *nums, int nums_len);

int main() {
    int num1 = 5, num2 = 10;
    int *ptr1, *ptr2;

    /* Set ptr1 and ptr2 to point to num1 and num2 respectively */
    ptr1 = &num1;
    ptr2 = &num2;

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);

    /* Call the swap function to swap the values of num1 and num2 */
    swap(ptr1, ptr2);

    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);

    int nums[] = {1, 2, 3, 4, 5};
    int nums_len = sizeof(nums) / sizeof(int);
    int sum = add_numbers(nums, nums_len);
    printf("The sum of the numbers in the array is %d\n", sum);

    return 0;
}

/* Function definition for swap */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Function definition for add_numbers */
int add_numbers(int *nums, int nums_len) {
    int sum = 0;
    for (int i = 0; i < nums_len; i++) {
        sum += *(nums + i);
    }
    return sum;
}