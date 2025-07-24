//FormAI DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to perform shape shifting
void shapeShift(char *text) {
    int len = strlen(text);
    // check length of text
    if (len > 50) {
        // if length is greater than 50, perform shape shifting
        for (int i = 0; i < len; i++) {
            if (text[i] >= 'a' && text[i] <= 'z') {
                // if character is lowercase, shift it 3 positions to the right
                text[i] = (text[i] - 'a' + 3) % 26 + 'a';
            }
            else if (text[i] >= 'A' && text[i] <= 'Z') {
                // if character is uppercase, shift it 3 positions to the left
                text[i] = (text[i] - 'A' - 3 + 26) % 26 + 'A';
            }
            else {
                // if character is not an alphabet, skip it
                continue;
            }
        }
    }
}

int main() {
    char text[1000];
    printf("Enter the text to shape shift:\n");
    // read input text
    fgets(text, sizeof(text), stdin);
    // remove newline character from input text
    text[strcspn(text, "\n")] = '\0';
    // perform shape shifting
    shapeShift(text);
    printf("Shape shifted text: %s\n", text);
    return 0;
}