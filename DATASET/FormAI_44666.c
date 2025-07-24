//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 2

char *beautify(char *input) {
    int i, j, k, level = 0;
    size_t len = strlen(input);
    char *output = malloc(len * sizeof(char));

    j = 0;
    for(i = 0; i < len; i++) {
        if(input[i] == '<') {
            if(input[i+1] == '/') level--;
            if(level > 0) {
                memset(output + j, ' ', level * INDENT_SIZE);
                j += level * INDENT_SIZE;
            }
            output[j++] = input[i];
            if(input[i+1] != '/') level++;
            output[j++] = '\n';
        } else if(input[i] == '>') {
            output[j++] = '>';
            output[j++] = '\n';
        } else {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';
    return output;
}

int main() {
    char input[] = "<html><head><title>Hello World</title></head><body><h1>Greetings!</h1></body></html>";

    char *output = beautify(input);
    printf("%s", output);

    free(output);
    return 0;
}