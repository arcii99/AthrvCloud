//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main() {
    char input[MAX_LENGTH];
    int word_count = 0;
    int i;

    printf("Enter a string: ");
    fgets(input, MAX_LENGTH, stdin);

    for(i = 0; input[i] != '\0'; i++) {
        if(isspace(input[i]) || ispunct(input[i])) {
            word_count++;
        }
    }

    if(input[0] != '\n') {
        word_count++;
    }

    printf("Number of words: %d\n", word_count);

    return 0;
}