//FormAI DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
}

void beautify(char* input) {
    int level = 0;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        if (input[i] == '<') {
            if (input[i+1] == '/') {
                level--;
                printf("\n");
                indent(level);
            } else {
                printf("\n");
                indent(level);
                level++;
            }
        }
        printf("%c", input[i]);
        if (input[i] == '>') {
            if (input[i-1] == '/') {
                level--;
            }
            printf("\n");
            indent(level);
        }
    }
}

int main() {
    char input[] = "<html><head><title>Page Title</title></head><body><h1>My First Heading</h1><p>My first paragraph.</p></body></html>";
    beautify(input);
    return 0;
}