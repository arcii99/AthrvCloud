//FormAI DATASET v1.0 Category: Word Count Tool ; Style: genious
#include <stdio.h>
#include <ctype.h>

int main() {
    char c, prev = '\0';
    int word_count = 0, char_count = 0, line_count = 0;

    printf("*** C Word Count Tool ***\n");
    printf("Enter text: \n");

    while ((c = getchar()) != EOF) {
        if (prev == '\0' || isspace(prev)) { // word start condition
            word_count++;
        }
        if (c == '\n') { // new line condition
            line_count++;
        }
        char_count++; // incrementing character count
        prev = c; // updating previous character
    }

    printf("\n");
    printf("Total characters: %d\n", char_count);
    printf("Total words: %d\n", word_count);
    printf("Total lines: %d\n", line_count);
    printf("\n");

    return 0;
}