//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000]; 
    int wordCount = 0, i;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; i < strlen(text); i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            wordCount++; 
        }
    }

    printf("Word count: %d\n", wordCount);

    return 0;
}