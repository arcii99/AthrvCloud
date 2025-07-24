//FormAI DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[100];
    int word_count = 0;
    int i;

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    for (i = 0; sentence[i] != '\0'; i++) {
        if (isspace(sentence[i]) || sentence[i] == '\n') {
            word_count++;
        }
    }

    printf("Word count: %d", word_count);

    return 0;
}