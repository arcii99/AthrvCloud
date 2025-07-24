//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    char output[100];
    char vowels[] = "aeiou";
    int counter = 0;
    int i, j, k;

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    for (i = 0; i < strlen(input); i++) {
        int not_vowel = 1;

        for (j = 0; j < strlen(vowels); j++) {
            if (input[i] == vowels[j]) {
                not_vowel = 0;
                break;
            }
        }

        if (not_vowel) {
            output[counter] = input[i];
            counter++;
        }
    }

    output[counter] = '\0';

    printf("Input: %sOutput: %s", input, output);

    return 0;
}