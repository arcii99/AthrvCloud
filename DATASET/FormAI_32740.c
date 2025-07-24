//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int count = 0, i;

    printf("Enter a string: ");
    fgets(text, 100, stdin);

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            count++;
        }
    }

    printf("Word count is %d", count + 1);

    return 0;
}