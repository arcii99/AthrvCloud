//FormAI DATASET v1.0 Category: Word Count Tool ; Style: post-apocalyptic
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

int main() {
    char c, prev_c, word[MAX_WORD_LEN];
    int i = 0, count = 0;

    printf("Welcome to the post-apocalyptic Word Count Tool\n");
    printf("Please enter your text: ");

    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            if (i < MAX_WORD_LEN-1) {
                word[i++] = tolower(c);
            }
            prev_c = c;
        } else {
            if (i > 0) {
                word[i] = '\0';
                if (strcmp(word, "c") == 0) {
                    count++;
                }
                i = 0;
            }
        }
    }

    if (i > 0) {
        word[i] = '\0';
        if (strcmp(word, "c") == 0) {
            count++;
        }
    }
    
    printf("The number of occurrences of 'c' in the text is %d\n", count);
    printf("Thank you for using the post-apocalyptic Word Count Tool.\n");

    return 0;
}