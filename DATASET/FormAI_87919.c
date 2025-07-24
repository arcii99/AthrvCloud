//FormAI DATASET v1.0 Category: Word Count Tool ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int word_count = 0;
    int i;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            word_count++;
        }
    }

    if (strlen(sentence) > 0) {
        word_count++;
    }

    printf("Word count: %d\n", word_count);

    return 0;
}