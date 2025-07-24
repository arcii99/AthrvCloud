//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>

/* Start of the program */
int main(void) {

    /* The input string */
    char input[100];

    /* Initializing the sanitizing variables */
    int found_alpha = 0;
    int found_digit = 0;
    int found_special = 0;

    /* Start by asking the user for input */
    printf("Good evening dear friend. Might I ask for your input?\n");
    fgets(input, sizeof(input), stdin);

    /* Loop through the input string */
    for(int i = 0; input[i] != '\0'; i++) {
        /* Check for alpha characters */
        if(isalpha(input[i])) {
            found_alpha = 1;
        }
        /* Check for digit characters */
        else if(isdigit(input[i])) {
            found_digit = 1;
        }
        /* Check for special characters */
        else if(!isspace(input[i])) {
            found_special = 1;
        }
    }

    /* Print the sanitized input */
    if(found_alpha && found_digit && found_special) {
        printf("I have taken the liberty of sanitizing your input for you: %s\n", input);
    }
    else {
        printf("I am sorry but your input does not meet the requirements. Please try again.\n");
    }

    /* End of the program */
    return 0;
}