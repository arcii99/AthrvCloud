//FormAI DATASET v1.0 Category: Binary Converter ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void binaryConverter(char input[]) {
    int len = strlen(input);
    char out[len + 1];
    int i,j,k,l,m,n;
    long int decimal = 0;
    int bin_arr[len];

    // Converting input string to integer
    for (i = 0; i < len; i++) {
        if (input[i] < '0' || input[i] > '1') {
            printf("Invalid Input: %s\n", input);
            return;
        }
        decimal = decimal * 2 + (input[i] - '0');
    }

    // Converting decimal to binary
    int quotient = decimal, remainder, count = 0;
    while (quotient != 0) {
        remainder = quotient % 2;
        bin_arr[count++] = remainder;
        quotient /= 2;
    }

    // Reversing the binary array and creating binary output string
    i = 0;
    while (count > 0) {
        out[i++] = bin_arr[--count] + '0';
    }
    out[i] = '\0';

    printf("Binary Equivalent: %s \n", out);
}

int main() {
    char input[10];
    printf("Enter Binary Number: ");
    scanf("%s", input);
    binaryConverter(input);
    return 0;
}