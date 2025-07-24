//FormAI DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printTabs(int numTabs) {
    for (int i = 0; i < numTabs; i++) {
        printf("\t");
    }
}

void beautifyHTML(char* html) {
    int numTabs = 0;
    int length = strlen(html);

    for (int i = 0; i < length; i++) {
        if (html[i] == '<') {
            if (html[i+1] == '/') {
                numTabs--;
            }
            printTabs(numTabs);
            printf("%c\n", html[i]);
            numTabs++;
        } else if (html[i] == '>') {
            printf("%c\n", html[i]);
        } else {
            printTabs(numTabs);
            printf("%c", html[i]);
            if (html[i+1] == '<') {
                printf("\n");
            }
        }
    }
}

int main() {
    char* html = "<html><head><title>Beautify Me</title></head><body><h1>Hello, world!</h1><p>This is a paragraph of text.</p></body></html>";
    beautifyHTML(html);
    return 0;
}