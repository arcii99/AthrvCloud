//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Ken Thompson
#include <stdio.h>

int main() {
    char c, prev;
    int count = 0;

    printf("Enter a string: ");
    while ((c = getchar()) != '\n') {
        if ((c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f') && prev != ' ') {
            count++;
        }
        prev = c;
    }
    if (prev != ' ') {
        count++;
    }

    printf("Word count: %d", count);

    return 0;
}