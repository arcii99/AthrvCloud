//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void beautify_html(const char* filename) {
    FILE* file = fopen(filename, "r");
    FILE* output = fopen("beautified.html", "w");
    char buffer[1024];
    char* ptr = buffer;
    int indent_level = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        while (isspace(*ptr)) ++ptr;
        switch (*ptr) {
        case '<':
            if (*(ptr+1) == '/') --indent_level;
            for (int i = 0; i < indent_level; ++i) {
                fputc('\t', output);
            }
            fputs(buffer, output);
            if (*(ptr+1) != '/') ++indent_level;
            break;
        default:
            fputs(buffer, output);
            break;
        }
    }
    fclose(file);
    fclose(output);
}

int main(void) {
    beautify_html("example.html");
    return 0;
}