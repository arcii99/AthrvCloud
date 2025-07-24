//FormAI DATASET v1.0 Category: Word Count Tool ; Style: recursive
#include <stdio.h>
#include <ctype.h>

int countWords(char string[]);
void stripPunctuation(char string[]);

int main() {
    char input[1000];

    printf("Enter a string: ");
    fgets(input, 1000, stdin);

    int numWords = countWords(input);
    printf("Number of words: %d\n", numWords);

    return 0;
}

int countWords(char string[]) {
    stripPunctuation(string);

    if (string[0] == '\0') {
        return 0;
    }

    int count;
    if (isspace(string[0])) {
        count = 0;
    } else {
        count = 1;
    }

    return count + countWords(&string[1]);
}

void stripPunctuation(char string[]) {
    char copy[1000];

    int i;
    int j = 0;
    for (i = 0; string[i] != '\0'; i++) {
        if (!ispunct(string[i])) {
            copy[j++] = string[i];
        }
    }

    copy[j] = '\0';
    strcpy(string, copy);
}