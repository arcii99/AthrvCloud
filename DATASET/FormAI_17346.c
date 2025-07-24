//FormAI DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>
int main() {
    char paragraph[1000];
    int i, len, count = 0;
    printf("Enter a paragraph of text: ");
    fgets(paragraph, 1000, stdin);
    len = strlen(paragraph);
    for (i = 0; i < len; i++) {
        if (paragraph[i] == ' ' || paragraph[i] == '\n') {
            count++;
        }
    }
    printf("The number of words in the paragraph is: %d\n", count);
    return 0;
}