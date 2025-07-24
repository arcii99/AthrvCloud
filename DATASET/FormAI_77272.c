//FormAI DATASET v1.0 Category: HTML beautifier ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void indent(int level);
void output(char c);
void newline();
void print(char* text);
void beautify(char* html);

int main()
{
    char* html = "<html><head><title>My Page</title></head><body><h1>Welcome to my page!</h1><p>This is some text.</p></body></html>";
    beautify(html);
    return 0;
}

void beautify(char* html)
{
    int level = 0;
    int in_tag = 0;
    int tag_start = 0;
    int len = strlen(html);
    for (int i = 0; i < len; i++) {
        char c = html[i];
        if (in_tag) {
            if (c == '>') {
                in_tag = 0;
                if (html[i-1] == '/') {
                    level--;
                }
                newline();
                indent(level);
                print(&html[tag_start]);
            }
            output(c);
        } else {
            if (c == '<') {
                in_tag = 1;
                tag_start = i;
                if (html[i+1] != '/') {
                    newline();
                    indent(level);
                    level++;
                } else {
                    level--;
                }
            }
            output(c);
        }
    }
    newline();
}

void indent(int level) 
{
    for (int i = 0; i < level; i++) {
        printf("    ");
    }
}

void output(char c)
{
    printf("%c", c);
}

void newline()
{
    printf("\n");
}

void print(char* text) 
{
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        output(text[i]);
    }
}