//FormAI DATASET v1.0 Category: HTML beautifier ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *html_code = "<body>\n<span class=\"name\">John Doe</span>\n<p class=\"message\">Hello world!</p>\n</body>";
    int indentation_level = 0;
    int i = 0;

    while (html_code[i] != '\0') {
        if (html_code[i] == '<' && html_code[i+1] != '/') {
            printf("\n");
            for (int j = 0; j < indentation_level; j++) {
                printf("    ");
            }
            printf("<");
            indentation_level++;
        } else if (html_code[i] == '<' && html_code[i+1] == '/') {
            printf("\n");
            indentation_level--;
            for (int j = 0; j < indentation_level; j++) {
                printf("    ");
            }
            printf("</");
        } else if (html_code[i] == '>') {
            printf(">");
        } else {
            printf("%c", html_code[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}