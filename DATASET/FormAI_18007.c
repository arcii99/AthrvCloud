//FormAI DATASET v1.0 Category: HTML beautifier ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify_html(char *html) {
    char *doc = malloc(strlen(html) + 1);
    char *start_tag = NULL;
    char *end_tag = NULL;
    int indent_level = 0;
    int i = 0;
    int j = 0;
    int verbatim = 0;
    int in_tag = 0;
    
    while (i < strlen(html)) {
        if (html[i] == '<') {
            end_tag = (html[i + 1] == '/') ? &html[i + 2] : &html[i + 1];
            while (*end_tag != '>' && *end_tag != ' ') {
                end_tag++;
            }
            if (*end_tag == ' ') {
                in_tag = 1;
            } else {
                in_tag = 0;
            }
            if (in_tag) {
                if (*end_tag == '\"' || *end_tag == '\'') {
                    verbatim = 1;
                }
            } else {
                if (*(start_tag - 1) == '/') {
                    indent_level--;
                }
            }
            if (start_tag == NULL) {
                for (j = 0; j < indent_level; j++) {
                    doc[i + j] = ' ';
                }
                start_tag = &doc[i];
            }
            if (*(end_tag - 1) == '/') {
                indent_level--;
            } else {
                indent_level++;
            }
        } else if (html[i] == '>') {
            if (verbatim) {
                verbatim = 0;
            } else {
                start_tag = NULL;
                doc[j++] = '\n';
            }
            in_tag = 0;
        }
        if (!in_tag) {
            doc[j++] = html[i];
        }
        i++;
    }
    doc[j] = '\0';
    printf("%s\n", doc);
    free(doc);
}

int main() {
    char html[] = "<!DOCTYPE html><html><head><title>HTML Beautifier</title></head><body><div><h1>Lorem ipsum</h1><p>Dolor sit amet, consectetur adipiscing elit. Fusce ut lectus non metus suscipit rhoncus nec vel ex. Sed placerat pretium elit in tempor. Mauris tempor sed magna eget commodo. Nulla eget bibendum nibh, et placerat nibh. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Maecenas malesuada erat vel felis aliquam, vel dictum felis malesuada.</p></div><img src=\"example.jpg\"><ul><li>Item 1</li><li>Item 2</li><li>Item 3</li></ul></body></html>";
    beautify_html(html);
    return 0;
}