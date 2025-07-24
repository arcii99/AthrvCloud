//FormAI DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int main()
{
    char html[MAX_SIZE];
    printf("Enter the HTML code:\n");
    fgets(html, MAX_SIZE, stdin);

    char beautified_html[MAX_SIZE];
    int index = 0;
    int indent_size = 4;
    int indent_level = 0;
    int len = strlen(html);

    for (int i = 0; i < len; i++) {
        if (html[i] == '<') {
            if (html[i + 1] == '/') {
                indent_level--;
            }
            for (int j = 0; j < indent_level * indent_size; j++) {
                beautified_html[index++] = ' ';
            }
            indent_level++;
        }
        beautified_html[index++] = html[i];
        if (html[i] == '>') {
            beautified_html[index++] = '\n';
        }
    }
    beautified_html[index] = '\0';

    printf("\nOriginal HTML code:\n%s", html);
    printf("\nBeautified HTML code:\n%s", beautified_html);

    return 0;
}