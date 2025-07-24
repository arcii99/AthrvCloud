//FormAI DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Function to trim whitespace from left of string
char* ltrim(char* str) {
    if (!str) {
        return NULL;
    }

    if(*str == ' ') {
        return ltrim(str + 1);
    }
    return str;
}

//Function to trim whitespace from right of string
char* rtrim(char* str) {
    if (!str) {
        return NULL;
    }

    char* end = str + strlen(str) - 1;
    while(end > str && *end == ' ') {
        end--;
    }
    *(end + 1) = '\0';
    return str;
}

//Function to check if character is a whitespace character
bool is_whitespace(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n');
}

//Function to beautify HTML code
void beautify_html(char* html_code) {
    char* cur_pos = html_code;
    int indent_level = 0;
    bool new_line_needed = false;

    while(*cur_pos != '\0') {
        //If the current character is a >, we need to indent on the next line
        if(*cur_pos == '>') {
            new_line_needed = true;
        }
        //If the current character is a <, we need to indent on the current line
        else if(*cur_pos == '<' && *(cur_pos + 1) != '/') {
            if(new_line_needed) {
                printf("\n");
                for(int i = 0; i < indent_level; i++) {
                    printf("    ");
                }
            }
            indent_level++;
            new_line_needed = true;
        }
        //If the current character is a </, we need to reduce the indent level and indent on the current line
        else if(*cur_pos == '<' && *(cur_pos + 1) == '/') {
            indent_level--;
            new_line_needed = true;
        }

        printf("%c", *cur_pos);
        cur_pos++;

        //If the current character is a whitespace character, we need to remove any extra whitespace characters
        if(is_whitespace(*cur_pos)) {
            while(is_whitespace(*(cur_pos + 1))) {
                cur_pos++;
            }
        }

        if(new_line_needed) {
            printf("\n");
            for(int i = 0; i < indent_level; i++) {
                printf("    ");
            }
            new_line_needed = false;
        }
    }
}

int main(void) {
    char* html_code = "<html>  <head>  <title>Page Title</title>  </head>  <body>  <h1>This is a Heading</h1>  <p>This is a paragraph.</p>  </body></html>";
    html_code = ltrim(rtrim(html_code));
    printf("Original HTML code:\n%s\n", html_code);
    printf("\nBeautified HTML code:\n");
    beautify_html(html_code);
    return 0;
}