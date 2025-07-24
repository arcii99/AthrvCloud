//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int wordCount = 0, i;

    printf("Enter a sentence: \n");
    fgets(sentence, 1000, stdin);

    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            wordCount++;
        }
    }

    if (sentence[strlen(sentence)-1] != ' ') {
        wordCount++;
    }

    printf("\n");
    printf("Upon my inspection, this sentence contains %d words.\n", wordCount);
    printf("\n");

    return 0;
}