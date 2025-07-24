//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_LENGTH 20

int main() {
    char color[MAX_COLOR_LENGTH + 1]; // this will hold the user's inputted color
    int i;

    printf("Welcome! Please tell us your favorite color: ");

    // read in the user's inputted color
    fgets(color, MAX_COLOR_LENGTH + 1, stdin);

    // remove any trailing newline characters
    for (i = 0; color[i] != '\0'; i++) {
        if (color[i] == '\n') {
            color[i] = '\0';
        }
    }

    // check that the inputted color is safe
    for (i = 0; i < strlen(color); i++) {
        if (!isalpha(color[i])) {
            printf("Sorry, we cannot accept that color. Please try again.\n");
            return 1;
        }
    }

    // if we've made it this far, the inputted color is safe!
    printf("Thank you for sharing your favorite color: %s\n", color);

    return 0;
}