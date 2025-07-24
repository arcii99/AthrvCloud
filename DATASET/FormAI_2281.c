//FormAI DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[1000];
    int count = 0, i;

    printf("Enter the text to count the number of words:\n");
    fgets(input, 1000, stdin);

    for (i = 0; input[i] != '\0'; i++) {
        if (isspace(input[i]) || input[i] == '\n') {
            count++;
        }
    }

    printf("The number of words in the input text is %d\n", count);

    return 0;
}