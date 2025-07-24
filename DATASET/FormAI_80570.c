//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// the Alien Language Translator program
int main() {
    char alienText[100];
    printf("Enter an alien word: ");
    scanf("%s", alienText);

    // converting the alien text
    for (int i = 0; i < strlen(alienText); i++) {
        if (alienText[i] == 'a') {
            alienText[i] = 'y';
        } else if (alienText[i] == 'b') {
            alienText[i] = 'z';
        } else if (alienText[i] >= 'c' && alienText[i] <= 'z') {
            alienText[i] = alienText[i] - 2;
        } else {
            // invalid character entered by user
            printf("Invalid character entered. Please enter a valid alien word.\n");
            exit(0);
        }
    }

    // printing the translated text
    printf("The translated alien word is: %s\n", alienText);

    return 0;
}