//FormAI DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int wordCount(char str[]);

int main() {
    char str[1000];
    printf("Enter the string: ");
    fgets(str, 1000, stdin);
    int count = wordCount(str);
    printf("Word count: %d\n", count);
    return 0;
}

int wordCount(char str[]) {
    int count = 0;
    bool inWord = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            inWord = false;
        }
        else if (!inWord) {
            inWord = true;
            count++;
        }
    }
    return count;
}