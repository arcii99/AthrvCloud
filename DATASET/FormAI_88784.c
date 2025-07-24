//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include <stdio.h>
#include <string.h>
#define TAB_SIZE 4

void beautify(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[1000] = "";
    int indent_level = 0;

    while (fgets(line, sizeof(line), file)) {
        int i;
        int line_len = strlen(line);
        int new_indent_level = indent_level;

        for (i = 0; i < line_len; i++) {
            if (line[i] == '<') {
                if (line[i+1] == '/') {
                    indent_level -= TAB_SIZE;
                } else {
                    if (line[i+1] != '!') {
                        new_indent_level += TAB_SIZE;
                    }
                }
            }
            if (line[i] == '>') {
                if (line[i-1] == '/') {
                    indent_level -= TAB_SIZE;
                }
            }
        }

        printf("%*s%s", indent_level, "", line);

        indent_level = new_indent_level;
    }

    fclose(file);
}

int main() {
    char *filename = "example.html";
    beautify(filename);
    return 0;
}