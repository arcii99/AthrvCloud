//FormAI DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
    //Declare variables
    char input[500];
    char* ptr;
    int word_count = 0;

    //Get user input
    printf("Input string: ");
    fgets(input, 500, stdin);

    //Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    //Loop through input and count words
    ptr = strtok(input, " ");
    while (ptr != NULL) {
        word_count++;
        ptr = strtok(NULL, " ");
    }

    //Output word count
    printf("Word count: %d\n", word_count);

    return 0;
}