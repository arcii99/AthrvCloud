//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract metadata from C source code
void extractMetadata(char *srcCode) {
    int len = strlen(srcCode);
    int numLines = 0, numChars = 0, numKeywords = 0, numFunctions = 0;

    for (int i = 0; i < len; i++) {
       if (srcCode[i] == '\n') {
            numLines++;
       }
       if (srcCode[i] != ' ' && srcCode[i] != '\n' && srcCode[i] != '\t') {
            numChars++;
       }
    }

    char *keywords[7] = {"void", "int", "char", "float", "double", "long", "short"};

    for (int i = 0; i < len; i++) {
        int isKeyword = 0;

        // Check if current word is a keyword
        for (int j = 0; j < 7; j++) {
            if (strncmp(&srcCode[i], keywords[j], strlen(keywords[j])) == 0) {
                numKeywords++;
                isKeyword = 1;
                break;
            }
        }

        // If current word is not a keyword, check if it is a function
        if (!isKeyword) {
            if (srcCode[i] == '(') {
                numFunctions++;
            }
        }
    }

    printf("Number of lines: %d\n", numLines);
    printf("Number of non-whitespace characters: %d\n", numChars);
    printf("Number of keywords: %d\n", numKeywords);
    printf("Number of functions: %d\n", numFunctions);
}

int main() {
    char srcCode[] = "void foo() {\n\tprintf(\"Hello, World!\\n\");\n}\n\nint main() {\n\tfoo();\n\treturn 0;\n}";

    printf("Source Code:\n%s\n\n", srcCode);

    printf("Metadata:\n");
    extractMetadata(srcCode);

    return 0;
}