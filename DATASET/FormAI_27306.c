//FormAI DATASET v1.0 Category: Error handling ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the function to check if a character is a digit
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// Define the function to convert a string to an integer
int stringToInt(char* str) {
    int num = 0;
    int sign = 1;
    int i = 0;

    // Check for negative sign
    if (str[0] == '-') {
        sign = -1;
        i = 1;
    }

    for (; str[i] != '\0'; i++) {
        // Check for non-digit characters
        if (!isDigit(str[i])) {
            printf("Error: %c is not a digit.\n", str[i]);
            exit(1);
        }

        num = num * 10 + (str[i] - '0');
    }

    return sign * num;
}

int main() {
    char input[10];
    printf("Enter an integer: ");
    scanf("%s", input);

    int num = stringToInt(input);
    printf("The integer is: %d\n", num);

    return 0;
}