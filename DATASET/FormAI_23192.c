//FormAI DATASET v1.0 Category: Word Count Tool ; Style: intelligent
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 20

int main() {
    char word[MAX_WORD_LEN + 1];
    int word_count = 0;
    int char_count = 0;
    int uppercase_count = 0;
    int lowercase_count = 0;
    int whitespace_count = 0;
    int digit_count = 0;
    int punct_count = 0;

    printf("Enter your text:\n");

    while (1) {
        int c = getchar();

        if (isspace(c) || c == EOF) {
            // End of current word
            if (char_count > 0) {
                // Print word stats
                printf("%.*s: %d chars, %d uppercase, %d lowercase, %d digits, %d punctuation\n", char_count, word, char_count, uppercase_count, lowercase_count, digit_count, punct_count);
                word_count++;
            }

            // Reset counts for next word
            char_count = 0;
            uppercase_count = 0;
            lowercase_count = 0;
            digit_count = 0;
            punct_count = 0;

            // Check if we have reached end of input
            if (c == EOF) {
                break;
            }
        } else {
            // Count the current character
            char_count++;

            if (char_count > MAX_WORD_LEN) {
                // Word is too long, discard the rest of it
                while ((c = getchar()) != EOF && !isspace(c)) {}
                char_count = 0;
                continue;
            }

            if (isupper(c)) {
                uppercase_count++;
            } else if (islower(c)) {
                lowercase_count++;
            } else if (isdigit(c)) {
                digit_count++;
            } else if (ispunct(c)) {
                punct_count++;
            }
        }
    }

    printf("\nTotal word count: %d\n", word_count);

    return 0;
}