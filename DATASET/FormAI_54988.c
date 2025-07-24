//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char code[1000];

    printf("Enter Code:\n");
    fgets(code, 1000, stdin);

    int indentation = 0;

    for (int i = 0; i < strlen(code); i++) {
        char c = code[i];

        if (c == ' ') continue;

        if (c == '<') {
            for (int j = 0; j < indentation; j++)
                printf("\t");
            printf("%c", c);
            indentation++;
        } else if (c == '>') {
            printf("%c\n", c);
            indentation--;
        } else if (c == '/') {
            for (int j = 0; j < indentation - 1; j++)
                printf("\t");
            printf("%c", c);
            if (code[i + 1] != '>')
                printf("\n");
        } else {
            for (int j = 0; j < indentation; j++)
                printf("\t");
            while (c != '<') {
                printf("%c", c);
                i++;
                c = code[i];
            }
            printf("\n");
            i--;
        }
    }

    return 0;
}