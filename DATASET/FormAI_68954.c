//FormAI DATASET v1.0 Category: HTML beautifier ; Style: safe
#include <stdio.h>

void printIndent(int indentLevel) {
    for (int i = 0; i < indentLevel; i++) {
        printf("    ");
    }
}

void beautifyHTML(char* html) {
    int indentLevel = 0;
    int i = 0;
    int inOpeningTag = 0;
    int inClosingTag = 0;
    int inString = 0;
    
    while (html[i] != '\0') {
        if (html[i] == '<') {
            if (html[i+1] == '/') {
                inClosingTag = 1;
                inOpeningTag = 0;
            } else {
                inOpeningTag = 1;
                inClosingTag = 0;
            }
            printIndent(indentLevel);
        }
        
        printf("%c", html[i]);
        
        if (html[i] == '>') {
            printf("\n");
            if (inClosingTag) {
                indentLevel--;
            } else if (inOpeningTag) {
                indentLevel++;
            }
            inClosingTag = 0;
            inOpeningTag = 0;
        }
        
        i++;
    }
}

int main() {
    char* html = "<html><head><title>My Title</title></head><body><h1>Welcome to my website!</h1><p>Thank you for visiting my website.</p></body></html>";

    beautifyHTML(html);

    return 0;
}