//FormAI DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char html_code[10000];
    char beautified_code[20000] = "";
    int indentation_level = 0;
    printf("Enter the HTML code:\n");
    fgets(html_code, 10000, stdin);

    for(int i = 0; i < strlen(html_code); i++) {
        if(html_code[i] == '<') {
            if(html_code[i+1] == '/') {
                indentation_level--;
            }
            for(int j = 0; j < indentation_level; j++) {
                strcat(beautified_code, "    ");
            }
            strcat(beautified_code, "<");
            indentation_level++;

        } else if(html_code[i] == '>') {
            strcat(beautified_code, ">\n");
        } else {
            strncat(beautified_code, &html_code[i], 1);
        }
    }
    printf("\nFormatted HTML code:\n%s", beautified_code);
    return 0;
}