//FormAI DATASET v1.0 Category: Word Count Tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char* str, int i, int count) {
    if (str[i] == '\0') {
        return count;
    }
    if (str[i] == ' ') {
        return countWords(str, i + 1, count);
    }
    if (i == 0 || str[i - 1] == ' ') {
        count++;
    }
    return countWords(str, i + 1, count);
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Word count: %d\n", countWords(str, 0, 0));
    return 0;
}