//FormAI DATASET v1.0 Category: Syntax parsing ; Style: ultraprecise
#include <stdio.h>

/* Main function */
int main() {

    /* Declare variables */
    char input[50]; /* input string */
    int i; /* iterator */
    int count = 1; /* count variable to keep track of brackets */

    /* Ask for user input */
    printf("Enter C code to check syntax:\n");
    fgets(input, 50, stdin);

    /* Loop through input string */
    for(i = 0; input[i] != '\0'; i++) {

        /* Check for opening bracket */
        if(input[i] == '{') {

            /* Increment count */
            count++;

        /* Check for closing bracket */
        } else if(input[i] == '}') {

            /* Decrement count */
            count--;

        }

    }

    /* Check final count variable */
    if(count == 1) {

        printf("Syntax is correct!\n");

    } else {

        printf("Syntax is incorrect!\n");

    }

    return 0;

}