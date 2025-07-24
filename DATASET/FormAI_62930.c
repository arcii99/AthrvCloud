//FormAI DATASET v1.0 Category: HTML beautifier ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// function declarations
void beautify_html(char*);

// main function
int main() {
    // input html code
    char html_code[1000] = "<html><head><title>My Page</title></head><body><h1>Welcome to My Page</h1><p>This is some text on my page</p></body></html>";

    // print original html code
    printf("Original HTML Code:\n%s\n\n", html_code);

    // call function to beautify html code
    beautify_html(html_code);

    // print beautified html code
    printf("Beautified HTML Code:\n%s\n", html_code);

    return 0;
}

// function to beautify html code
void beautify_html(char* html_code) {
    int indent_level = 0;
    char* output_code = (char*) malloc(1000 * sizeof(char));
    char* temp_code = (char*) malloc(1000 * sizeof(char));
    char* tag_name = (char*) malloc(100 * sizeof(char));
    int code_length = strlen(html_code);
    int i = 0, j = 0;

    // loop through html code
    while (i < code_length) {
        // check if opening tag
        if (html_code[i] == '<') {
            // check if closing tag
            if (html_code[i+1] == '/') {
                indent_level--;
            }

            // print indent for current level
            for (j = 0; j < indent_level; j++) {
                strcat(output_code, "\t");
            }

            // get tag name
            j = 0;
            while (html_code[i+j] != ' ' && html_code[i+j] != '>') {
                tag_name[j] = html_code[i+j];
                j++;
            }
            tag_name[j] = '\0';

            // add tag to output code
            strcat(output_code, "<");
            strcat(output_code, tag_name);

            // add rest of tag
            j = i + j;
            while (html_code[j] != '>') {
                strncat(output_code, &html_code[j], 1);
                j++;
            }
            strcat(output_code, ">");

            // check if self-closing tag
            if (html_code[j-1] == '/') {
                strcat(output_code, "\n");
            } else {
                strcat(output_code, "\n");
                indent_level++;
            }

            i = j;
        } else {
            // get text between tags
            j = i;
            while (html_code[j] != '<') {
                strncat(temp_code, &html_code[j], 1);
                j++;
            }
            temp_code[j-i] = '\0';

            // print indent for current level
            for (j = 0; j < indent_level; j++) {
                strcat(output_code, "\t");
            }

            // add text to output code
            strcat(output_code, temp_code);
            strcat(output_code, "\n");

            i = j;
        }
    }

    // copy beautified code back to input html code
    strcpy(html_code, output_code);

    // free memory
    free(output_code);
    free(temp_code);
    free(tag_name);
}