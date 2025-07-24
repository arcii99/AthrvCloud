//FormAI DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *open_file(char *filename);   // Function to open and read a file
void beautify_html(char *html);    // Function to beautify HTML code

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./htmlbeautifier [filename]\n");
        exit(1);
    }

    char *html = open_file(argv[1]);

    beautify_html(html);

    printf("The beautified HTML code:\n%s", html);

    free(html);

    return 0;
}

char *open_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *html = calloc(file_size + 1, sizeof(char));

    fread(html, sizeof(char), file_size, file);

    fclose(file);

    return html;
}

void beautify_html(char *html) {
    int indentation_level = 0;
    int in_tag = 0;   // Boolean flag to keep track if we are inside a tag
    int in_comment = 0;   // Boolean flag to keep track if we are inside a comment
    int in_string = 0;   // Boolean flag to keep track if we are inside a string
    char current_char = '\0';
    char previous_char = '\0';
    int i = 0;

    while (html[i] != '\0') {
        current_char = html[i];

        switch (current_char) {
            case '<':
                if (!in_string && !in_comment) {
                    in_tag = 1;
                    if (isspace(previous_char)) {
                        // There is a space before this tag, so we indent
                        indentation_level++;
                    }
                }
                break;
            case '>':
                if (!in_string && !in_comment) {
                    in_tag = 0;
                    if (previous_char == '/') {
                        // This is a self-closing tag, so we don't indent it
                        indentation_level--;
                    }
                }
                break;
            case '-':
                if (!in_string && !in_tag) {
                    if (previous_char == '<') {
                        // This is the start of an HTML comment
                        in_comment = 1;
                    } else if (previous_char == '-' && html[i - 2] == '!') {
                        // This is the end of an HTML comment
                        in_comment = 0;
                    }
                }
                break;
            case '"':
            case '\'':
                if (!in_comment) {
                    if (in_string && previous_char != '\\' && html[i - 1] != current_char) {
                        // We are ending a string
                        in_string = 0;
                    } else if (!in_string) {
                        // We are starting a string
                        in_string = 1;
                    }
                }
                break;
            case '\n':
                if (!in_string && !in_comment) {
                    // This is a new line,
                    // so we add the appropriate indentation
                    html[i] = '\0'; // Remove newline character
                    strcat(html, "\n");
                    int j;
                    for (j = 0; j < indentation_level; j++) {
                        strcat(html, "\t");
                    }
                    strcat(html, "");
                }
            default:
                break;
        }

        previous_char = current_char;
        i++;
    }
}