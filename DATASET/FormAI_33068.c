//FormAI DATASET v1.0 Category: Word Count Tool ; Style: synchronous
#include <stdio.h>

int main() {
    char text[1000], c;
    int count = 0;

    printf("Enter text: ");

    while ((c = getchar()) != '\n') {
        text[count] = c;
        count++;
    }

    text[count] = '\0';

    printf("\nNumber of words: %d\n", wordCount(text));

    return 0;
}

int wordCount(char text[]) {
    int count = 0, i;

    if (text[0] != ' ') {
        count++;
    }

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' && text[i+1] != ' ') {
            count++;
        }
    }

    return count;
}