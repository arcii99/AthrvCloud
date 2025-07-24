//FormAI DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[2000], output[2000];
    int indent = 0, i, j, k, l;
    printf("Enter your HTML code: ");
    fgets(input, 2000, stdin);
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if (input[i] == '<') {
            for (k = i; input[k] != '>' && input[k] != '\0'; k++);
            if (input[k] == '>') {
                output[j++] = '\n';
                for (l = 0; l < indent; l++) output[j++] = '\t';
                indent++;
            }
        }
        output[j++] = input[i];
        if (input[i] == '>') {
            output[j++] = '\n';
            indent--;
            for (l = 0; l < indent; l++) output[j++] = '\t';
        }
    }
    output[j] = '\0';
    printf("\nYour beautified code is:\n%s", output);
    return 0;
}