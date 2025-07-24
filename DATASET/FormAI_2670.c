//FormAI DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char* html, char* beautified) {
    int i, j, indent_level = 0;
    char* tag;
    char* temp = (char*)malloc(sizeof(char) * strlen(html));

    j = 0;
    for (i = 0; i < strlen(html); ++i) {
        if (html[i] == '<') {
            //Handle opening and closing tags
            if (html[i + 1] == '/') {
                tag = strtok(&html[i + 2], ">");
                indent_level--;
            }
            else {
                tag = strtok(&html[i + 1], ">");
                indent_level++;
            }
            memset(temp, ' ', sizeof(temp));
            temp[indent_level * 4] = '\0';
            sprintf(&beautified[j], "\n%s<%s>", temp, tag);
            j = strlen(beautified);

            if (html[i + 1] != '/') {
                i += strlen(tag);
            }
            else {
                i += strlen(tag) + 1;
            }
        }
        else if (html[i] == '>') {
            sprintf(&beautified[j], ">%c", html[i + 1]);
            j = strlen(beautified) - 1;
            if (html[i + 1] != '<' && html[i + 1] != '/') {
                sprintf(&beautified[j], "\n%s", temp);
                j = strlen(beautified);
            }
            i++;
        }
        else {
            sprintf(&beautified[j], "%c", html[i]);
            j++;
        }
    }
    beautified[j] = '\0';
    free(temp);
}

int main() {
    char html[1000] = "<html><head><title>Example</title></head><body><h1>Example Heading</h1><p>Example paragraph.</p></body></html>";
    char beautified[2000];
    beautify(html, beautified);
    printf("Original HTML:\n %s\n", html);
    printf("\nBeautified HTML:\n %s\n", beautified);
}