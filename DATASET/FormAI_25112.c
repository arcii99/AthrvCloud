//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;

    printf("Enter some text: ");
    fgets(text, 1000, stdin);

    for(int i = 0; i < strlen(text); i++) {
        char c = text[i];

        if(isalpha(c)) {
            c = tolower(c);

            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if(isdigit(c)) {
            digits++;
        } else if(c == ' ') {
            spaces++;
        }
    }

    printf("\nVowels: %d\nConsonants: %d\nDigits: %d\nSpaces: %d\n", vowels, consonants, digits, spaces);

    return 0;
}