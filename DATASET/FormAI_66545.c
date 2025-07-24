//FormAI DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 10000

void beautifyHTML(char *input) {
    int i, j, len = strlen(input);
    int indentation = 0;
    char output[MAX_INPUT_SIZE] = "";

    for (i = 0; i < len; i++) {
        if (input[i] == '<' && input[i+1] != '/') {
            for (j = 0; j < indentation; j++) {
                strcat(output, "\t");
            }
            strcat(output, "<");
            indentation++;
        }
        else if (input[i] == '<' && input[i+1] == '/') {
            indentation--;
            for (j = 0; j < indentation; j++) {
                strcat(output, "\t");
            }
            strcat(output, "</");
        }
        else if (input[i] == '>' && input[i-1] != '/') {
            strcat(output, ">\n");
        }
        else {
            strncat(output, &input[i], 1);
        }
    }
    printf("%s", output);
}

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Enter HTML code:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    beautifyHTML(input);

    return 0;
}