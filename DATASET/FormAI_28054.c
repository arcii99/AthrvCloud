//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: genious
#include <stdio.h>
#include <string.h>

void countCharFrequency(char* str) {
    int alphabet[26] = {0}; // initializing the frequency of each alphabet to 0
    int i;

    for (i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            // incrementing the frequency of the alphabet encountered
            alphabet[str[i] - 'a']++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            // converting uppercase letters to lowercase and incrementing frequency
            alphabet[str[i] - 'A']++;
        }
    }

    printf("The character frequency of the string is:\n");

    for (i = 0; i < 26; i++) {
        if (alphabet[i] != 0) {
            printf("%c occurs %d times\n", i + 'a', alphabet[i]);
        }
    }
}

int main() {
    printf("Welcome to the Genius style C Word Frequency Counter!\n");

    char inputStr[1000];

    printf("Please enter a string to count its character frequency:\n");
    fgets(inputStr, 1000, stdin);

    // removing the newline character at the end of the input string
    inputStr[strcspn(inputStr, "\n")] = 0;

    countCharFrequency(inputStr);

    return 0;
}