//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char english[1000];
    int i, j;

    // Ask for user input
    printf("Enter an English sentence to translate into Cat Language:\n");
    fgets(english, 1000, stdin);

    // Loop through each character in the input
    for (i = 0; i < strlen(english); i++) {
        // If the character is a space, print a meow
        if (english[i] == ' ') {
            printf("meow ");
        }
        // If the character is a vowel, print a purr
        else if (english[i] == 'a' || english[i] == 'A' || english[i] == 'e' || english[i] == 'E' || english[i] == 'i' || english[i] == 'I' || english[i] == 'o' || english[i] == 'O' || english[i] == 'u' || english[i] == 'U') {
            printf("purr ");
        }
        // Otherwise, print a meow and the uppercase version of the character
        else {
            printf("meow %c ", toupper(english[i]));
        }
    }

    printf("\n");
    return 0;
}