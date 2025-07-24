//FormAI DATASET v1.0 Category: HTML beautifier ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[5000];
int indent_level = 0;

void indent() {
    int i;
    for (i = 0; i < indent_level * 4; i++) {
        printf(" ");
    }
}

void new_line() {
    printf("\n");
}

void parse_html(char* html) {
    char* token = strtok(html, "<>");
    while (token != NULL) {
        if (token[0] == '/') {
            indent_level--;
        }
        indent();
        printf("%s", token);
        if (token[0] != '/') {
            new_line();
            indent_level++;
        } else {
            new_line();
        }
        token = strtok(NULL, "<>");
    }
}

int main() {
    FILE* file = fopen("example.html", "r");
    if (file == NULL) {
        printf("Failed to open file.");
        return -1;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        parse_html(buffer);
    }

    fclose(file);
    return 0;
}