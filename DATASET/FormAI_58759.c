//FormAI DATASET v1.0 Category: HTML beautifier ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

void printIndent(int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
}

void beautifyHTML(char* input) {
    int inputLen = strlen(input);
    int indent = 0;
    for (int i = 0; i < inputLen; i++) {
        if (input[i] == '<') {
            if (input[i+1] == '/') {
                indent--;
            }
            printIndent(indent);
            printf("%c", input[i]);
            if (input[i+1] != '/') {
                indent++;
            }
            printf("\n");
        } else if (input[i] == '>') {
            printf("%c\n", input[i]);
        } else if (input[i] == ' ') {
            printf("%c", input[i]);
            while (input[i+1] != '<' && input[i+1] != '>') {
                printf("%c", input[i+1]);
                i++;
            }
            printf("\n");
        } else {
            printf("%c", input[i]);
        }
    }
}

int main() {
    char* input = "<html><head><title>My Page</title></head><body><h1>Welcome to my page!</h1><p>This is a paragraph.</p></body></html>";
    beautifyHTML(input);
    return 0;
}