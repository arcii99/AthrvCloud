//FormAI DATASET v1.0 Category: Word Count Tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    int word_count = 0, i, len;
    printf("Enter a sentence: ");
    scanf("%[^\n]", input);

    len = strlen(input);
    for (i = 0; i < len; i++) {
        if (input[i] == ' ') {
            word_count++;
        }
    }

    // Count the last word as well
    word_count++;

    printf("The sentence has %d words.\n", word_count);
    return 0;
}