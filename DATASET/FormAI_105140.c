//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int wordCount(char *str) {
    int count = 0;

    while (*str) {
        // skip leading white space
        while (*str && isspace(*str)) {
            ++str;
        }
        if (*str) {
            ++count;
        }
        // skip word
        while (*str && !isspace(*str)) {
            ++str;
        }
    }

    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");

    if (fgets(str, 100, stdin)) {
        int count = wordCount(str);
        printf("The string contains %d words.\n", count);
    }

    return 0;
}