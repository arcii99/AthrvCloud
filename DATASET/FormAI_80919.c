//FormAI DATASET v1.0 Category: HTML beautifier ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 10000

char buffer[MAXSIZE];
int IndentLevel = 0;

// Function to add indentation
void Indent() {
    for (int i = 0; i < IndentLevel; i++) {
        printf("\t");
    }
}

// Function to check if a character is a whitespace
int IsWhiteSpace(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n');
}

int main() {

    int c;
    int insideTag = 0;

    // Read input HTML from standard input
    while ((c = getchar()) != EOF) {
        // If inside a tag, just print the character and continue
        if (insideTag) {
            putchar(c);
            // If we see a closing tag, decrease the indentation level
            if (c == '>') {
                printf("\n");
                insideTag = 0;
                IndentLevel--;
                Indent();
            }
            continue;
        }
        // If we see an open angle bracket, start of a tag.
        if (c == '<') {
            // If it's a close tag, decrease the indentation level
            if (getchar() == '/') {
                printf("\n");
                IndentLevel--;
            }
            else {
                // Otherwise, increase the indentation level
                printf("\n");
                IndentLevel++;
                Indent();
            }
            insideTag = 1;
        }
        putchar(c);
        // If we see the end of a line, print indentation as well
        if (c == '\n') {
            Indent();
        }
    }
    return 0;
}