//FormAI DATASET v1.0 Category: Data validation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    char input[100];
    int i, is_int = 1;

    printf("Please enter an integer: ");
    fgets(input, 100, stdin);

    // Check if input is empty or too long
    if (input[0] == '\n' || input[99] != '\0') {
        printf("Input is invalid!\n");
        return -1;
    }

    // Check if input contains non-digit characters
    for (i = 0; input[i] != '\n'; i++) {
        if (!isdigit(input[i])) {
            is_int = 0;
            break;
        }
    }

    // Check if input is an integer
    if (is_int) {
        int num = atoi(input);
        printf("You entered the integer %d.\n", num);
    } else {
        printf("Input is not an integer!\n");
        return -1;
    }

    return 0;
}