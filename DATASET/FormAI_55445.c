//FormAI DATASET v1.0 Category: HTML beautifier ; Style: real-life
#include <stdio.h>
#include <string.h>

void indent(int count) {
    for(int i = 0; i < count; i++) {
        printf("    ");
    }
}

void beautify(char* html) {
    int indent_level = 0;
    int length = strlen(html);

    for(int i = 0; i < length; i++) {
        char c = html[i];

        if(c == '<') {
            printf("\n");
            indent(indent_level);
            printf("%c", c);

            if(html[i + 1] == '/') {
                indent_level--;
            }
            else {
                indent_level++;
            }
        }
        else if(c == '>') {
            printf("%c", c);

            if(html[i - 1] == '/') {
                indent_level--;
            }
        }
        else if(c == '/') {
            printf("%c", c);

            if(html[i - 1] == '<') {
                indent_level--;
            }
        }
        else {
            printf("%c", c);
        }
    }
}

int main() {
    char html[] = "<html><head><title>My Webpage</title></head><body><h1>Welcome to my webpage</h1><p>This is where I share all my thoughts</p></body></html>";

    beautify(html);

    return 0;
}