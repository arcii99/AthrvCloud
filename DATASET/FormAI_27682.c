//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char alienLanguage[] = "akjsdhnmmoqweryttyytwwzxcjuiuiopllkjhgfdsabncvx";
    char english[] = "abcdefghijklmnopqrstuvwxyz";
    char input[100];

    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter a phrase to translate: ");
    fgets(input, 100, stdin);

    int i, j, length;
    length = strlen(input);

    for (i = 0; i < length; i++) {
        // check if character is a letter
        if (isalpha(input[i])) {
            // check if character is uppercase
            if (isupper(input[i])) {
                for (j = 0; j < 26; j++) {
                    // if letter exists in alien language, replace with corresponding english letter
                    if (input[i] == toupper(alienLanguage[j])) {
                        printf("%c", toupper(english[j]));
                        break;
                    }
                }
            }
            // character is lowercase
            else {
                for (j = 0; j < 26; j++) {
                    // if letter exists in alien language, replace with corresponding english letter
                    if (input[i] == alienLanguage[j]) {
                        printf("%c", english[j]);
                        break;
                    }
                }
            }
        }
        // character is not a letter, print as-is
        else {
            printf("%c", input[i]);
        }
    }

    printf("\nTranslation complete! Goodbye.\n");

    return 0;
}