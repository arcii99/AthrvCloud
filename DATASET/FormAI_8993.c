//FormAI DATASET v1.0 Category: HTML beautifier ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char code[10000];
    int tab_count = 0;
    int code_length = 0;
    char c;
    printf("Enter your C/HTML code:\n");
    while((c = getchar()) != EOF) {
        code[code_length] = c;

        if(c == '{') {
            tab_count++;
        }
        if(c == '}') {
            tab_count--;
            if(code[code_length - 1] != '\n') {
                printf("\n");
            }
            for(int i = 0; i < tab_count; i++) {
                printf("\t");
            }

        }
        if(c == ';' || c == '{' || c == '}') {
            code[code_length + 1] = '\0';
            printf("%s", code);
            memset(code, 0, sizeof(code));
            code_length = -1;
            if(c == '{') {
                printf("\n");
                for(int i = 0; i < tab_count; i++) {
                    printf("\t");
                }
            }
            if(c == '}') {
                printf("\n");
            }
        }
        code_length++;
    }
    return 0;
}