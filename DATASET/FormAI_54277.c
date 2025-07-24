//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

void beautify_html(char* file_name) {
    FILE* input_file = fopen(file_name, "r");
    FILE* output_file = fopen("beautified.html", "w");
    if(input_file == NULL || output_file == NULL) {
        printf("Error opening files!\n");
        exit(1);
    }
    int indent_level = 0;
    char c;
    while((c = fgetc(input_file)) != EOF) {
        if(c == '<') {
            fprintf(output_file, "\n");
            for(int i = 0; i < indent_level; i++) {
                fprintf(output_file, "    ");
            }
            fprintf(output_file, "<");
            if(fgetc(input_file) == '/') {
                indent_level--;
            }
            else {
                indent_level++;
            }
        }
        fprintf(output_file, "%c", c);
        if(c == '>') {
            if(fgetc(input_file) != '<') {
                fprintf(output_file, "\n");
                for(int i = 0; i < indent_level; i++) {
                    fprintf(output_file, "    ");
                }
            }
        }
    }
    fclose(input_file);
    fclose(output_file);
}

int main() {
    beautify_html("index.html");
    return 0;
}