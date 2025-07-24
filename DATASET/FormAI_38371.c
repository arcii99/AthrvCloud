//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char input_string[MAX_LENGTH];
    int word_count = 0, i;

    printf("Enter a string: ");
    fgets(input_string, MAX_LENGTH, stdin);

    for (i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == ' ' && input_string[i-1] != ' ') {
            word_count++;
        }
    }

    if (input_string[0] != ' ') {
        // increase the word count if the first character is not a space
        word_count++;
    }

    printf("Word count: %d\n", word_count);
    
    return 0;
}