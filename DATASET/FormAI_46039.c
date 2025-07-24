//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int countWords(char s[]);
int isWhiteSpace(char c);

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Total words in the string: %d", countWords(str));
    return 0;
}

int countWords(char s[]) {
    int wordCount = 0, i = 0;
    while (s[i] != '\0') {
        if (isWhiteSpace(s[i])) {
            wordCount++;
            while (isWhiteSpace(s[i]))
                i++;
        }
        else i++;
    }
    return wordCount + 1;
}

int isWhiteSpace(char c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
        return 1;
    return 0;
}