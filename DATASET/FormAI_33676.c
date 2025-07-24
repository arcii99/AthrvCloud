//FormAI DATASET v1.0 Category: Error handling ; Style: mind-bending
#include <stdio.h>

// A custom error handling function
void error(char* message) {
    printf("\nERROR: %s!\n", message);
    printf("Terminating program...\n");
    exit(1);
}

int main() {
    printf("Welcome to the mind-bending error handling program!\n");

    int i, num;
    char str[10];

    // First, we'll ask the user for a number
    printf("\nEnter a number: ");
    if(scanf("%d", &num) != 1) {
        error("Invalid input detected");
    }

    // Now, we'll ask the user for a string
    printf("Enter a string: ");
    if(scanf("%s", str) != 1) {
        error("Invalid input detected");
    }

    // Let's try to parse the string into an integer and add it to the number
    printf("Parsing the string and adding it to the number...\n");
    for(i = 0; i < 10; i++) {
        if(str[i] == '\0') break; // End of string
        if(str[i] < '0' || str[i] > '9') {
            error("Invalid string entered");
        }
        num += str[i] - '0';
    }

    // Finally, we'll print out the resulting number
    printf("The result is: %d\n", num);

    return 0;
}