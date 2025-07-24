//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include <stdio.h>
#include <string.h>

void beautifyHTML(char* code) {
    int indentLevel = 0;
    int codeLength = strlen(code);
    int i = 0;
    int j = 0;

    while (i < codeLength) {
        if (code[i] == '<') {
            // Check if it's the closing tag
            if (code[i+1] == '/') {
                indentLevel--;
            }

            // Indentation
            for (int k = 0; k < indentLevel; k++) {
                printf("\t");
            }

            // Print tag
            while (code[i] != '>') {
                printf("%c", code[i]);
                i++;
            }
            printf("%c", code[i]);
            i++;

            // Newline
            printf("\n");

            // Check if it's the opening tag
            if (code[i] != '/') {
                indentLevel++;
            }
        }
        else {
            // Print code
            while (code[i] != '<') {
                printf("%c", code[i]);
                i++;
            }
            printf("\n");
        }
        i++;
    }
}

int main() {
    char code[] = "<html>\n<head>\n</head>\n<body>\n  <div>\n    <h1>Hello, World!</h1>\n  </div>\n</body>\n</html> \n";
    beautifyHTML(code);

    return 0;
}