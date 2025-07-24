//FormAI DATASET v1.0 Category: Word Count Tool ; Style: brave
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {

    char ch, word[MAX_LENGTH];
    int word_count = 0, i = 0, flag = 0;

    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {

        if (isalpha(ch)) {
            word[i] = ch;
            i++;
            flag = 1;
        } else if (flag == 1) {
            word[i] = '\0';
            word_count++;
            i = 0;
            flag = 0;
        }

    }

    if (flag == 1) {
        word[i] = '\0';
        word_count++;
    }

    printf("\nNumber of words in the sentence: %d\n", word_count);

    return 0;
}