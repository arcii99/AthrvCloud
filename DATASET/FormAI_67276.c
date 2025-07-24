//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string to translate into cat language: ");
    fgets(input, sizeof(input), stdin);

    // Replace vowels with "meow"
    for(int i = 0; i < strlen(input); i++) {
        if(input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            input[i] = 'm';
            input[i+1] = 'e';
            input[i+2] = 'o';
            input[i+3] = 'w';
            i += 3; // skip over added characters
        }
    }

    printf("Translated string: %s", input);
    return 0;
}