//FormAI DATASET v1.0 Category: Word Count Tool ; Style: genious
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[10000];
    printf("Enter the sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    int wordCount = 0, length = strlen(sentence), i;
    for (i = 0; i < length; i++) {
        if ((sentence[i] == ' ' && sentence[i - 1] != ' ') || (sentence[i] == '\n' && sentence[i - 1] != ' ')) {
            wordCount++;
        }
    }

    if (wordCount == 0 && sentence[0] != '\n') {
        wordCount = 1;
    }

    printf("\nThe word count of the given sentence is %d.\n", wordCount);

    return 0;
}