//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>

void print_indentation(int indentation) {
    int i;
    for (i=0; i<indentation; i++){
         printf("    ");
    }
}

int beautify_html(char* html, int indentation) {
    int i = 0, tag_st = 0, tag_end = 0, tag_len = 0;
    while (html[i] != '\0') {
        if (html[i] == '<') {
            if (html[i+1] == '/') {
                print_indentation(indentation-1);
                putchar('<');
                tag_len = i - tag_st;
                for (int j=0; j < tag_len; j++){
                    putchar(html[tag_st+j]);
                }
                tag_len = 0;
                tag_st = i;
                while (html[i] != '>') {
                    putchar(html[i]);
                    i++;
                }
                putchar('>');
                print_indentation(indentation-1);
                putchar('\n');
                indentation--;
                tag_st = i+1;
            } else {
                print_indentation(indentation);
                putchar('<');
                tag_st = i+1;
                while (html[i] != '>') {
                    putchar(html[++i]);
                }
                printf(">\n");
                indentation++;
            }
        }
        if (html[i] == '\n') {
            putchar('\n');
        }
        if (html[i] != '<' && html[i] != '>') {
            putchar(html[i]);
        }
        i++;
    }
    printf("\n");
    return 0;
}

int main() {
    char* html = "<html>\n<head>\n<title>Example HTML Page</title>\n</head>\n<body>\n<h1>Sample Heading</h1>\n<p>Bunch of text in a paragraph tag</p>\n</body>\n<html>";
    beautify_html(html, 0);
    return 0;
}