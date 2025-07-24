//FormAI DATASET v1.0 Category: Word Count Tool ; Style: calm
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int words = 0;
    int i, charCount;

    printf("Enter text: ");
    fgets(text, 1000, stdin);

    charCount = strlen(text);

    for (i = 0; i < charCount; i++) {
        if (isspace(text[i]) || text[i] == '\n') {
            words++;
        }
    }

    printf("\nWord count: %d", words);

    return 0;
}