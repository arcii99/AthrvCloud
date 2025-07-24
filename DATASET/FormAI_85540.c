//FormAI DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[10000];
    char output[20000];
    int indent = 0;
    int i, j, k;

    printf("Enter input HTML code: \n");
    fgets(input, 10000, stdin);

    for (i = 0, j = 0; i < strlen(input); i++) {
        if (input[i] == '<') {
            if (input[i+1] == '/') {
                indent -= 4;
            }

            for (k = 0; k < indent; k++) {
                output[j++] = ' ';
            }

            if (input[i+1] != '!') {
                indent += 4;
            }
        }

        output[j++] = input[i];

        if (input[i] == '>') {
            if (input[i-1] == '/') {
                indent -= 4;
            }

            if (input[i-1] != '/') {
                output[j++] = '\n';
            }
        }
    }

    printf("\nOutput HTML code: \n\n%s\n", output);

    return 0;
}