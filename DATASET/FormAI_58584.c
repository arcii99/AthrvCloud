//FormAI DATASET v1.0 Category: Word Count Tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int countWords(char *str, int len);

int main() {
    char str[100];
    printf("Enter a sentence:\n");
    fgets(str, 100, stdin);
    int len = strlen(str);
    int count = countWords(str, len);
    printf("The sentence contains %d words.\n", count);
    return 0;
}

int countWords(char *str, int len) {
    if (len == 0) {
        return 0;
    }
    int count = 0;
    int i = 0;
    while (i < len && isspace(str[i])) {
        i++;
    }
    if (i == len) {
        return 0;
    }
    while (i < len && !isspace(str[i])) {
        i++;
    }
    count++;
    return count + countWords(str + i, len - i);
}