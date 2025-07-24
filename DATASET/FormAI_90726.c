//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1

char input[] = "<html><head><title>My Website</title></head><body><h1>Welcome to My Awesome Website!</h1><p>Thank you for visiting my website. It is still under construction, so please bear with me. Check back soon for updates.</p><ul><li>Home</li><li>About</li><li>Contact</li></ul></body></html>";
char output[1000];

int beautify(char *input, char *output) {
    int indent_level = 0;
    char *p = input;
    char *q = output;
    char indent[100];

    *q = '\0';

    while (*p != '\0') {
        if (*p == '<') {
            if (*(p + 1) == '/') {
                indent_level--;
                strcpy(indent, "");
                for (int i = 0; i < indent_level; i++) {
                    strcat(indent, "  ");
                }
                p += 2;
            } else {
                strcpy(indent, "");
                for (int i = 0; i < indent_level; i++) {
                    strcat(indent, "  ");
                }
                indent_level++;
            }
            strcat(q, "\n");
            strcat(q, indent);
        }
        
        if (*p == '>') {
            strcat(q, ">");
            if (*(p - 1) == '/') {
                indent_level--;
            }
            if (*(p + 1) == '<' && *(p + 2) != '/') {
                strcat(q, "\n");
                strcat(q, indent);
            }
        }
        
        if (*p != '<' && *p != '>') {
            strncat(q, p, 1);
        }
        
        p++;
    }

    return SUCCESS;
}

int main() {
    if (beautify(input, output) == FAILURE) {
        printf("Error beautifying HTML.\n");
        return FAILURE;
    }

    printf("%s\n", output);

    return SUCCESS;
}