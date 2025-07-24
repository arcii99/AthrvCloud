//FormAI DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char text[1000];
    int count = 0;

    printf("Enter your string: ");
    fgets(text, 1000, stdin);

    // count number of words
    for (int i=0; i<strlen(text); i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            count++;
        }
    }

    printf("Number of words: %d\n", count);

    return 0;
}