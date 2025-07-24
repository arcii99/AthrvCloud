//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
/* The Case of the Disordered HTML */
/* Written by the famous detective, Sherlock Holmes */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to beautify the given HTML code
void beautify_HTML(char* code) {
    // Initialize the variables
    char* formatted_code = (char*)malloc(sizeof(char) * strlen(code));
    int indentation_level = 0;
    int newline_flag = 0;

    // Loop through the entire code
    for (int i = 0; i < strlen(code); i++) {
        // If a new line character is encountered
        if (code[i] == '\n') {
            formatted_code[i] = code[i];
            newline_flag = 1;
        }
        // If a open tag is encountered
        else if (code[i] == '<' && code[i + 1] != '/') {
            if (newline_flag == 1) {
                for (int j = 0; j < indentation_level; j++) {
                    strcat(formatted_code, "\t");
                }
                newline_flag = 0;
            }
            strcat(formatted_code, "<");
            indentation_level++;
        }
        // If a close tag is encountered
        else if (code[i] == '<' && code[i + 1] == '/') {
            indentation_level--;
            if (newline_flag == 1) {
                for (int j = 0; j < indentation_level; j++) {
                    strcat(formatted_code, "\t");
                }
                newline_flag = 0;
            }
            strcat(formatted_code, "</");
            i++;
        }
        // If other characters are encountered
        else {
            if (newline_flag == 1) {
                for (int j = 0; j < indentation_level; j++) {
                    strcat(formatted_code, "\t");
                }
                newline_flag = 0;
            }
            strcat(formatted_code, &code[i]);
            while (i < strlen(code) - 1 && code[i + 1] != '<') {
                i++;
                strcat(formatted_code, &code[i]);
            }
            strcat(formatted_code, "\n");
            newline_flag = 1;
        }
    }

    // Print the beautified HTML code
    printf("The beautified HTML code is:\n");
    printf("%s", formatted_code);
}

int main() {
    char code[] = "<html><head><title>My Page</title></head><body><h1>Welcome to my page!</h1><p>Here is some text.</p></body></html>";
    beautify_HTML(code);
    return 0;
}