//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: standalone
#include <stdio.h>
#include <string.h>

// Function to translate the input string from Alien language to English
void translate(char input[]) {
    int i, j, k, len;

    // Determine the length of the input string
    len = strlen(input);

    // Loop through each character in the input string
    for (i = 0; i < len; i++) {
        // Check if the current character is a vowel
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            // If it is, output the corresponding alien character
            switch (input[i]) {
                case 'a':
                    printf("▲");
                    break;
                case 'e':
                    printf("◆");
                    break;
                case 'i':
                    printf("♥");
                    break;
                case 'o':
                    printf("★");
                    break;
                case 'u':
                    printf("◊");
                    break;
            }
        } else {
            // If it's not a vowel, output the character as is
            printf("%c", input[i]);
        }

        // Check if the current character is a space
        if (input[i] == ' ') {
            // If it is, output a special alien character for spaces
            printf("□");
        }
    }

    printf("\n");
}

int main() {
    char input[100];

    // Get input from the user
    printf("Enter a string in Alien language: ");
    fgets(input, sizeof(input), stdin);

    // Remove the trailing newline from the input
    input[strcspn(input, "\n")] = 0;

    // Translate the input string to English
    translate(input);

    return 0;
}