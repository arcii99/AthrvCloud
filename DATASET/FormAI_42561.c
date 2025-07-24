//FormAI DATASET v1.0 Category: HTML beautifier ; Style: shape shifting
#include <stdio.h>

#define INDENT "    " // Change the number of spaces for indentation

void printSpaces(int count) {
    // This function prints out "count" number of spaces
    printf("%*s", count, "");
}

void beautifyHTML(char* htmlCode) {
    int currentIndent = 0;
    char currentChar, nextChar;
    int i;

    for (i = 0; htmlCode[i] != '\0'; i++) {
        currentChar = htmlCode[i];
        nextChar = htmlCode[i+1];

        if (currentChar == '<') {
            if (nextChar == '/') { // This is a closing tag
                currentIndent -= 1;
            }
            printSpaces(currentIndent * strlen(INDENT));
            printf("%c", currentChar);
            currentIndent += 1;
        } else if (currentChar == '>') {
            printf("%c\n", currentChar);
        } else {
            printf("%c", currentChar);
        }
    }
}

int main() {
    char* htmlCode = "<html><head><title>My Website</title></head><body><h1>Welcome!</h1><p>This is my website.</p></body></html>";
    beautifyHTML(htmlCode);
    return 0;
}