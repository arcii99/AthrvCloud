//FormAI DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INDENT "    "

void indent(int *level) {
    for(int i=0; i<*level; i++) {
        printf(INDENT);
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error: can't open file %s\n", argv[1]);
        exit(1);
    }

    int indent_level = 0;
    char buffer[100];
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Remove leading and trailing whitespaces
        char *trimmed = buffer;
        int i = 0, j = strlen(trimmed) - 1;
        while(i <= j && (trimmed[i] == ' ' || trimmed[i] == '\t' || trimmed[i] == '\n')) i++;
        while(j >= i && (trimmed[j] == ' ' || trimmed[j] == '\t' || trimmed[j] == '\n')) j--;
        trimmed[j+1] = '\0';
        trimmed = &trimmed[i];

        // Skip empty lines
        if(trimmed[0] == '\0') {
            continue;
        }

        // Check if the line ends with a closing tag
        int ends_with_closing_tag = 0;
        if (trimmed[0] == '<' && trimmed[1] == '/') {
            ends_with_closing_tag = 1;
        }

        // Check if the line contains only a closing tag
        int contains_only_closing_tag = 0;
        if(ends_with_closing_tag && strlen(trimmed) == 3) {
            contains_only_closing_tag = 1;
        }

        if(ends_with_closing_tag && indent_level > 0) {
            indent_level--;
        }

        // Indent the line according to the current indent level
        indent(&indent_level);

        printf("%s\n", trimmed);

        // Increase indent level if the line opens a new tag
        if(trimmed[0] == '<' && !ends_with_closing_tag && !contains_only_closing_tag) {
            indent_level++;
        }
    }

    fclose(fp);
    return 0;
}