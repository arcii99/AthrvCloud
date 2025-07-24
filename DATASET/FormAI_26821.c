//FormAI DATASET v1.0 Category: Syntax parsing ; Style: safe
#include <stdio.h>
#include <string.h>

void parseString(char *str) {
    // Check for keywords and identifiers
    char *keywords[10] = {"int", "float", "double", "char", "long", "short", "signed", "unsigned", "void", "struct"};
    char *identifiers[10];
    int keywordsCounter = 0, identifiersCounter = 0;

    // Find keywords and identifiers in the input string
    char *token = strtok(str, " ");
    while (token != NULL) {
        // Check if the token is a keyword
        int i;
        for (i = 0; i < 10; i++) {
            if (strcmp(token, keywords[i]) == 0) {
                keywordsCounter++;
                break;
            }
        }

        // If token is not a keyword, then it's an identifier
        if (i == 10) {
            identifiers[identifiersCounter] = token;
            identifiersCounter++;
        }

        token = strtok(NULL, " ");
    }

    // Print the results
    printf("Keywords found: %d\n", keywordsCounter);
    printf("Identifiers found: %d\n", identifiersCounter);
    printf("Identifiers:\n");
    int j;
    for (j = 0; j < identifiersCounter; j++) {
        printf("%s\n", identifiers[j]);
    }
}

int main() {
    // Test the parseString function
    char str[] = "int foo float bar struct baz double qux char corge long grault short garply";
    parseString(str);
    return 0;
}