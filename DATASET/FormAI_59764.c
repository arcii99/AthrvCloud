//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Shape shifting function
void shapeShift(char *toShift) {
    int length = strlen(toShift);
    for (int i = 0; i < length; i++) {
        if (toShift[i] == 'o') {
            toShift[i] = 'u';
        } else if (toShift[i] == 'i') {
            toShift[i] = 'e';
        } else if (toShift[i] == 'a') {
            toShift[i] = 'i';
        } else if (toShift[i] == 'e') {
            toShift[i] = 'o';
        } else if (toShift[i] == 'u') {
            toShift[i] = 'a';
        }
    }
}

int main(void) {
    // Example input text
    char input[] = "The quick brown fox jumps over the lazy dog.";
    printf("Original text: %s\n", input);

    // Tokenize the input
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Apply shape shifting
        shapeShift(token);
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}