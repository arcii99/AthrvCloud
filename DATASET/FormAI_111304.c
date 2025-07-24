//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void beautify_code(char* file_name);

int main(int argc, char* argv[]) {
    if(argc == 2) {
        beautify_code(argv[1]);
    }
    else {
        printf("Error: Invalid arguments.\n");
        printf("Usage: ./html_beautifier file_name.html\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

void beautify_code(char* file_name) {
    FILE* fp;
    char current_char, previous_char = '\0';
    int indent_level = 0;

    fp = fopen(file_name, "r");

    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    while((current_char = fgetc(fp)) != EOF) {
        if(current_char == '<' && previous_char != '/') {
            printf("\n");
            for(int i = 0; i < indent_level; i++) {
                printf("\t");
            }
            indent_level++;
        }
        else if(current_char == '>') {
            if(previous_char == '/') {
                indent_level--;
            }
            printf("%c\n", current_char);
        }
        else {
            printf("%c", current_char);
        }
        previous_char = current_char;
    }

    fclose(fp);
}