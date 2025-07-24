//FormAI DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter a sentence:\n");
    fgets(input, 1000, stdin); // read input sentence

    int count = 0; // initialize word count to zero
    char *token = strtok(input, " "); // get first word
    while (token != NULL) {
        count++; // increment word count
        token = strtok(NULL, " "); // get next word
    }

    printf("There are %d words in the sentence.\n", count);

    return 0;
}