//FormAI DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int count = 0;
    char text[1000];
    printf("Enter your text: ");
    fgets(text, sizeof(text), stdin);
    for (int i=0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            count++;
        }
    }
    printf("Word count is %d.\n", count+1);
    return 0;
}