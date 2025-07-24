//FormAI DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void indent(int level) {
    for(int i=0; i<level; i++) {
        printf("    ");
    }
}

int main() {
    char input[10000];
    char output[10000];
    int level = 0;

    printf("Enter the HTML code to beautify:\n");
    fgets(input, 10000, stdin);

    char *token = strtok(input, "<>");

    while(token != NULL) {
        if(token[0] == '/') {
            level--;
        }
        indent(level);
        printf("<%s>\n", token);
        if(token[0] != '/') {
            level++;
        }
        token = strtok(NULL, "<>");
    }

    return 0;
}