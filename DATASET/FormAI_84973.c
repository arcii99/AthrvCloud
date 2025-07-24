//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    // initialize variables
    char input[50];
    int i;

    // ask for user input
    printf("What is your name, dear user? ");
    fgets(input, sizeof(input), stdin);

    // sanitize user input
    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            input[i] = toupper(input[i]); // capitalize all letters
        } else if (isspace(input[i])) {
            input[i] = '_'; // replace spaces with underscores
        } else {
            input[i] = '-'; // replace other characters with dashes
        }
    }

    // output sanitized input
    printf("Aha! So your name is %s.\n", input);
    printf("Tell me, dear user, what brings you to my humble abode?\n");
    fgets(input, sizeof(input), stdin);

    // sanitize user input (again)
    for (i = 0; i < strlen(input); i++) {
        if (isalpha(input[i])) {
            input[i] = tolower(input[i]); // convert all letters to lowercase
        } else if (isspace(input[i])) {
            input[i] = '-'; // replace spaces with dashes
        } else {
            input[i] = '_'; // replace other characters with underscores
        }
    }

    // output sanitized input (again)
    printf("Interesting choice of words, dear user. You said: %s\n", input);

    return 0;
}