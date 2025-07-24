//FormAI DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void print_tabs(int num_tabs) {
    while(num_tabs--) putchar('\t');
}

int main() {
    char c = getchar();
    int num_tabs = 0;
    while(c != EOF) {
        if(c == '<') {
            putchar(c);
            c = getchar();
            if(c == '/') {
                num_tabs--;
            }
            putchar('\n');
            print_tabs(num_tabs);
            if(c == '/') {
                num_tabs++;
            }
        } else if(c == '>') {
            putchar(c);
            putchar('\n');
            print_tabs(num_tabs);
        } else if(c == '\n' || isspace(c)) {
            putchar(c);
        } else {
            putchar(c);
        }
        c = getchar();
    }
    return 0;
}