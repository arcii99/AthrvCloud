//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[10000], output[10000], c;
    int i = 0, j = 0, tabDepth = 0, inTag = 0;

    printf("Enter the input HTML:\n");
    fgets(input, sizeof(input), stdin);

    while(input[i] != '\0') {
        c = input[i++];

        if(c == '<') {
            inTag = 1;
            output[j++] = c;

            if(input[i] == '/') tabDepth--;
            else tabDepth++;

            output[j++] = '\n';
            for(int k = 0; k < tabDepth; k++) output[j++] = '\t';
        }
        else if(c == '>') {
            inTag = 0;
            output[j++] = c;
            output[j++] = '\n';
        }
        else {
            output[j++] = c;

            if(!inTag && (isspace(c) || c == '>')) {
                output[j++] = '\n';
                for(int k = 0; k < tabDepth; k++) output[j++] = '\t';
            }
        }
    }

    printf("Beautified HTML:\n%s", output);

    return 0;
}