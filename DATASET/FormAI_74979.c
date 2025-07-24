//FormAI DATASET v1.0 Category: HTML beautifier ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to remove trailing whitespaces
char* rtrim(char* str) {
    int len = strlen(str);
    char* end = str + len - 1;
    while(end > str && isspace(*end))
        end--;
    *(end+1) = '\0';
    return str;
}

// function to remove leading whitespaces
char* ltrim(char* str) {
    while(isspace(*str))
        str++;
    return str;
}

// function to beautify the HTML code
char* beautify_html(char* html) {
    char* output = malloc(strlen(html) * sizeof(char));
    int indent_level = 0;
    int newline_flag = 0;
    int index = 0;
    char* token = strtok(html, "<>");
    while(token != NULL) {
        rtrim(token);
        ltrim(token);
        if(strcmp(token, "") == 0) { // ignore empty tokens
            token = strtok(NULL, "<>");
            continue;
        }
        if(token[0] == '/') { // decrease indent level
            indent_level--;
        }
        if(newline_flag) { // add newline character and tabs
            output[index++] = '\n';
            for(int i = 0; i < indent_level; i++)
                output[index++] = '\t';
            newline_flag = 0;
        }
        output[index++] = '<';
        if(token[0] == '/') { // add forward slash for closing tag
            output[index++] = '/';
        }
        strcat(output, token);
        if(token[strlen(token) - 1] == '>') { // increase indent level
            newline_flag = 1;
            indent_level++;
        }
        token = strtok(NULL, "<>");
    }
    output[index] = '\0';
    return output;
}

int main() {
    // test the beautify_html function
    char* html = "<html><head><title>My Website</title></head><body><h1>Hello World!</h1></body></html>";
    char* beautified_html = beautify_html(html);
    printf("Original HTML:\n%s\n", html);
    printf("Beautified HTML:\n%s\n", beautified_html);
    free(beautified_html);
    return 0;
}