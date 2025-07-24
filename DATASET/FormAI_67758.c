//FormAI DATASET v1.0 Category: Funny ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Surprise! You are running a unique and funny C program!\n");

    // Declare an integer variable and assign it a value
    int num = 10;

    // Declare a pointer variable and assign it the address of 'num'
    int *ptr = &num;

    // Print the value of 'num' and the address of 'ptr'
    printf("The value of 'num' is: %d\n", num);
    printf("The address of 'num' is: %p\n", &num);
    printf("The address of 'ptr' is: %p\n", ptr);

    // Change the value of 'num' using the pointer variable 'ptr'
    *ptr = 20;

    // Print the new value of 'num' and the address of 'num'
    printf("The new value of 'num' is: %d\n", num);
    printf("The address of 'num' is still: %p\n", &num);

    // Declare an array of characters and print each character using pointer arithmetic
    char str[] = "Surprise!";
    char *str_ptr = str;

    printf("Printing each character in 'str' using pointer arithmetic:\n");
    while (*str_ptr != '\0') {
        printf("%c ", *str_ptr);
        str_ptr++;
    }
    printf("\n");

    printf("Congratulations, you have successfully run a unique and funny C program!\n");

    return 0;
}