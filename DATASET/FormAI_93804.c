//FormAI DATASET v1.0 Category: Data validation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 50

/* Prototype */
bool is_number(char []);

int main(void) {

    char input[MAX_SIZE];
    bool valid_number = false;

    printf("Enter a valid number: ");
    do {
        fgets(input, MAX_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if (is_number(input)) {
            valid_number = true;
        } else {
            printf("Invalid input. Please enter a valid number: ");
        }
    } while(!valid_number);

    int number = atoi(input);
    printf("You entered %d\n", number);
    return 0;
}

bool is_number(char input[]) {
    /* Check if string is a number */
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return true;
}