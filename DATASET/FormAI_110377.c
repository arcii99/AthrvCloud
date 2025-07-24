//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char code[1000]; // assuming maximum 1000 characters in HTML code
    char temp[1000];
    int indent_level = 0;

    printf("Enter the HTML code:\n");
    fgets(code, 1000, stdin); // take input from user

    printf("\n\nFormatted code:\n\n");

    char *token = strtok(code, "\n"); // split code into lines
    while (token != NULL) {
        strcpy(temp, token);
        if (strstr(token, "</") != NULL) { // if line contains closing tag
            indent_level--;
        }

        for (int i = 0; i < indent_level; i++) { // add indent spaces
            printf("    ");
        }
        printf("%s\n", temp); // print formatted line

        if (strstr(token, "<") != NULL && strstr(token, "/>") == NULL && strstr(token, "</") == NULL) { // if line contains opening tag
            indent_level++;
        }

        token = strtok(NULL, "\n"); // move to next line
    }

    return 0;
}