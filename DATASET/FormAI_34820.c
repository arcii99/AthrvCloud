//FormAI DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    char input[BUFFER_SIZE], processed[BUFFER_SIZE];
    int vowels = 0, consonants = 0, digits = 0, spaces = 0, punctuation = 0;

    printf("Enter a string (max %d characters): ", BUFFER_SIZE - 1);
    fgets(input, BUFFER_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    // process input string
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (c >= '0' && c <= '9') {
            digits++;
        } else if (c == ' ') {
            spaces++;
        } else if (c == '.' || c == ',' || c == ':' || c == ';' || c == '?' || c == '!') {
            punctuation++;
        }
    }

    // copy input string to processed string with modified spacing
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            if (input[i+1] == ' ') { // skip consecutive spaces
                continue;
            } else if (input[i+1] == '.') { // space before period
                processed[j++] = '.';
            } else { // single space between words
                processed[j++] = ' ';
            }
        } else {
            processed[j++] = input[i];
        }
    }
    processed[j] = '\0'; // add null terminator

    // print results
    printf("Input string: %s\n", input);
    printf("Processed string: %s\n", processed);
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    printf("Punctuation: %d\n", punctuation);

    return 0;
}