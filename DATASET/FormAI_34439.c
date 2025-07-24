//FormAI DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    for (int i = 0; i < strlen(sentence); i++) {
        if (isspace(sentence[i])) {
            wordCount++;
        }
    }

    if (wordCount == 0) {
        printf("The sentence has 1 word.\n");
    }
    else {
        printf("The sentence has %d words.\n", wordCount + 1);
    }

    return 0;
}