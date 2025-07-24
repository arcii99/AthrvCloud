//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int count_words(char *str);

int main() {
    char str[MAX_LENGTH];
    int num_words;

    printf("Enter a sentence: ");
    fgets(str, MAX_LENGTH, stdin);

    num_words = count_words(str);
    printf("The sentence contains %d words.\n", num_words);

    return 0;
}

int count_words(char *str) {
    int count = 0;
    int state = 0;  // 0 for outside word, 1 for inside word

    for (int i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            state = 0;
        } else if (state == 0) {
            state = 1;
            count++;
        }
    }

    return count;
}