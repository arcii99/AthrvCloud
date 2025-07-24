//FormAI DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_HTML(char *input_file_name, char *output_file_name) {
    char line[2000], cleaned_line[2000], current_indent[1000], *ptr, *ptr2;
    FILE *input_file, *output_file;
    int indent_level = 0, line_length, i, j;

    input_file = fopen(input_file_name, "r");
    output_file = fopen(output_file_name, "w");

    while (fgets(line, 2000, input_file)) {
        line_length = strlen(line);
        j = 0;
        for (i = 0; i < line_length; i++) {
            if (line[i] == '<') {
                if (line[i + 1] == '/') {
                    indent_level--;
                }
                for (int k = 0; k < indent_level; k++) {
                    current_indent[j++] = '\t';
                }
                indent_level++;
                current_indent[j++] = '\t';
            }

            cleaned_line[j++] = line[i];

            if (line[i] == '>') {
                cleaned_line[j] = '\0';
                if (strstr(cleaned_line, "</") != NULL) {
                    indent_level--;
                }
                fprintf(output_file, "%s\n", cleaned_line);
                j = 0;
                cleaned_line[0] = '\0';
            }
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    beautify_HTML("input.html", "output.html");
    return 0;
}