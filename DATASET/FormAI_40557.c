//FormAI DATASET v1.0 Category: HTML beautifier ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 500

//helper function to check if a given character is a whitespace or not
bool is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n');
}

//function to remove leading and trailing whitespaces from a given string
void trim(char* s) {
    int i, j;
    for (i = 0; is_whitespace(*(s + i)); i++);
    for (j = strlen(s) - 1; j >= 0 && is_whitespace(*(s + j)); j--);
    *(s + j + 1) = '\0';
    memmove(s, s + i, j - i + 2);
}

//function to beautify a given HTML string
void beautify_html(char* html) {
    int i, j, k, level = 0;
    bool newline = true;
    char indent[MAX_SIZE];
    memset(indent, ' ', sizeof(indent));
    for (i = 0; *(html + i); i++) {
        if (*(html + i) == '<') {
            if (*(html + i + 1) == '/') {
                level--;
                newline = true;
            }
            else {
                level++;
                newline = true;
            }
            if (newline) {
                printf("\n");
                for (j = 0; j < level - 1; j++) {
                    printf("%s", indent);
                }
            }
            printf("%c", *(html + i));
            if (*(html + i + 1) != '/') {
                newline = true;
            }
            else {
                newline = false;
            }
        }
        else if (*(html + i - 1) == '>') {
            if (!is_whitespace(*(html + i)) && !is_whitespace(*(html + i - 2))) {
                printf(" ");
            }
            printf("%c", *(html + i));
            newline = false;
        }
        else {
            if (newline) {
                for (j = 0; j < level; j++) {
                    printf("%s", indent);
                }
                newline = false;
            }
            printf("%c", *(html + i));
        }
    }
    printf("\n");
}

int main() {
    char html[MAX_SIZE] = "<html><head><title>Welcome</title></head><body><h1><center>Welcome to my webpage!</center></h1><p>This is a sample webpage created using C program.</p></body></html>";
    trim(html);
    beautify_html(html);
    return 0;
}