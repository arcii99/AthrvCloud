//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>

int main() {
    int sum = 0;
    char str[1000];
    printf("Enter a string with only hexadecimal values: ");

    // read input string from user
    fgets(str, sizeof(str), stdin);

    // iterate through every alternate character in string
    for (int i = 0; i < strlen(str); i += 2) {
        // convert hexadecimal characters to decimal
        int first_digit = str[i] >= 'A' ? (str[i] & 0xdf) - 55 : str[i] - '0';
        int second_digit = str[i + 1] >= 'A' ? (str[i + 1] & 0xdf) - 55 : str[i + 1] - '0';

        // add the decimal value of the characters to sum
        sum += first_digit * 16 + second_digit;
    }

    // take complement of sum
    sum = ~sum;

    // print the checksum in hexadecimal format
    printf("Checksum calculated: %X\n", sum);
    return 0;
}