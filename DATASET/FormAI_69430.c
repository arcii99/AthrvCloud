//FormAI DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>
#include <stdbool.h>

void indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("    "); // four spaces
    }
}

void print_tag(char* tag, bool is_end, int level) {
    indent(level);
    if (is_end) {
        printf("</%s>\n", tag);
    } else {
        printf("<%s>\n", tag);
    }
}

void beautify(char* html, int length) {
    int level = 0;
    bool in_tag = false;
    bool in_quote = false;
    char quote_type;
    for (int i = 0; i < length; i++) {
        if (html[i] == '<') {
            in_tag = true;
            print_tag("", false, level);
            level++;
        } else if (html[i] == '>') {
            in_tag = false;
            level--;
            print_tag("", true, level);
        } else if (html[i] == '"' || html[i] == '\'') {
            if (in_quote) {
                if (html[i] == quote_type) {
                    in_quote = false;
                }
            } else {
                in_quote = true;
                quote_type = html[i];
            }
            putchar(html[i]);
        } else {
            putchar(html[i]);
        }
        if (!in_tag && !in_quote && html[i] == '\n') {
            print_tag("", false, level);
        }
    }
}

int main() {
    char html[] = "<html>\n<head>\n<title>My Page</title>\n</head>\n<body>\n<h1>Welcome to my page!</h1>\n<p>Here is some text.</p>\n</body>\n</html>";
    int length = sizeof(html) / sizeof(html[0]);
    beautify(html, length);
    return 0;
}