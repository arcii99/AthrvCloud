//FormAI DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char str[MAX_SIZE], word[MAX_SIZE], ch;
    int i, j, len, count;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    j = 0;
    count = 0;
    for (i = 0; str[i] != '\0'; i++) {
        ch = str[i];
        if (isspace(ch)) {
            word[j] = '\0';
            count++;
            j = 0;
        } else {
            word[j++] = ch;
        }
    }

    word[j] = '\0';
    if (j > 0) {
        count++;
    }

    printf("The number of words in the string is %d.\n", count);

    return 0;
}