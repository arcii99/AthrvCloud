//FormAI DATASET v1.0 Category: Educational ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024 

/* Function to check the validity of an input string */
int is_valid_input(char* input_str) {
    int valid = 1;
    int i;
    char character;

    for (i = 0; i < strlen(input_str); i++) {
        character = input_str[i];
        if (character < '0' || character > '9') {
            valid = 0;
            break;
        }
    }

    return valid;
}

int main(void) {
    char input_str[MAX_INPUT_LENGTH]; // buffer to hold input string
    int input_num;
    int result;

    printf("Enter an integer number: ");
    fgets(input_str, MAX_INPUT_LENGTH, stdin); // reading user input from console
    input_str[strcspn(input_str, "\n")] = 0; // removing trailing newline from input string

    if (!is_valid_input(input_str)) {
        printf("Invalid input!\n");
        return 1;
    }

    input_num = atoi(input_str); // converting input string to integer

    /* Do some calculation with the input number */
    result = 2 * input_num;

    printf("The result of 2 times %d is: %d\n", input_num, result);

    return 0;
}