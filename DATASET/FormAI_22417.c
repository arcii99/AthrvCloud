//FormAI DATASET v1.0 Category: Word Count Tool ; Style: recursive
#include <stdio.h>

int countWords(char *str);
int isSpace(char c);

int main() {
    char str[] = "The quick brown fox jumped over the lazy dog.";
    int count = countWords(str);
    printf("Word count: %d", count);
    return 0;
}

int countWords(char *str) {
    if (*str == '\0') { // Base case: End of string
        return 0;
    } else {
        int count = isSpace(*str) ? 0 : 1; // If the current character is a space, count is 0. Otherwise, count is 1.
        return count + countWords(str + 1); // Recurse through the rest of the string
    }
}

int isSpace(char c) {
    if (c == ' ' || c == '\n' || c == '\t') { // Check for space characters
        return 1;
    } else {
        return 0;
    }
}