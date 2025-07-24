//FormAI DATASET v1.0 Category: Word Count Tool ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int wordCount = 0;
    int i;

    printf("Enter a string: ");
    fgets(text, 100, stdin);

    for (i = 0; i < strlen(text); i++) {
        if (text[i] == ' ') {
            wordCount++;
        }
    }

    if (text[strlen(text) - 1] != ' ') {
        wordCount++;
    }

    printf("Word Count: %d\n", wordCount);

    return 0;
}