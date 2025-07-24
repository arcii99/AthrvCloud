//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cryptic
#include <stdio.h>
#include <string.h>

void alien_language_translator(char *string) {
    int length = strlen(string);
    int i;
    for (i = 0; i < length; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = 'c' + 'e' - string[i];
        }
        else if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = 'C' + 'E' - string[i];
        }
    }
    printf("Translated string: %s\n", string);
}

int main() {
    char string[100];
    printf("Enter a string in alien language: ");
    scanf("%[^\n]s", string);
    alien_language_translator(string);
    return 0;
}