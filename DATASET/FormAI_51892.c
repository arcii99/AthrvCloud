//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Claude Shannon
#include <stdio.h>
#include <ctype.h>

int main() {
    char text[1000];
    int charCount = 0, wordCount = 0, lineCount = 0, spaceCount = 0;

    printf("Enter the text:\n");

    while (fgets(text, sizeof(text), stdin)) {
        if (text[0] == '\n') {
            break;
        }
        lineCount++;
        int i = 0;
        while (text[i] != '\0') {
            if (isalpha(text[i])) {
                charCount++;
                while (isalpha(text[++i]));
                wordCount++;
            } else if (isspace(text[i])) {
                spaceCount++;
                while (isspace(text[++i]));
            } else {
                i++;
            }
        }
    }

    printf("\nText entered is:\n%s", text);
    printf("\nCharacter count: %d\n", charCount);
    printf("Word count: %d\n", wordCount);
    printf("Line count: %d\n", lineCount);
    printf("Space count: %d\n", spaceCount);

    return 0;
}