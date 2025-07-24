//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate checksum
unsigned int calc_checksum(char *str) {
    int len = strlen(str);
    unsigned int checksum = 0;

    // loop through each character in string and calculate checksum
    for (int i = 0; i < len; i++) {
        checksum += str[i];
    }

    return checksum;
}

int main() {
    char str[50];
    unsigned int checksum;
    int num1, num2;

    // get input from user
    printf("Enter a string: ");
    fgets(str, 50, stdin);

    // calculate checksum of string
    checksum = calc_checksum(str);

    // get two integers from user
    printf("Enter two integers, separated by a space: ");
    scanf("%d %d", &num1, &num2);

    // add checksum to the sum of the two integers
    int result = num1 + num2 + checksum;

    // output result
    printf("The result is: %d\n", result);

    return 0;
}