//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: interoperable
#include <stdio.h>
#include <string.h>

int main() {
    char ccat_code[1000];
    printf("Enter the C Cat code to translate: ");
    fgets(ccat_code, 1000, stdin);

    int cursor_pos = 0;
    char c_code[1000];
    int i = 0;

    while(ccat_code[cursor_pos] != '\0') {
        if(ccat_code[cursor_pos] == 'm') {
            c_code[i] = 'p';
            i++;
            c_code[i] = 'u';
            i++;
            c_code[i] = 'r';
            i++;
            c_code[i] = 'r';
            i++;
            c_code[i] = ';';
            i++;
            cursor_pos++;
        }
        else if(ccat_code[cursor_pos] == 'w') {
            c_code[i] = 'p';
            i++;
            c_code[i] = 'r';
            i++;
            c_code[i] = 'i';
            i++;
            c_code[i] = 'n';
            i++;
            c_code[i] = 't';
            i++;
            c_code[i] = 'f';
            i++;
            c_code[i] = '(';
            i++;
            cursor_pos++;
            while(ccat_code[cursor_pos] != '\n') {
                if(ccat_code[cursor_pos] == 'm') {
                    c_code[i] = '+';
                    i++;
                    c_code[i] = '+';
                    i++;
                    cursor_pos++;
                }
                else if(ccat_code[cursor_pos] == 'l') {
                    c_code[i] = '-';
                    i++;
                    c_code[i] = '-';
                    i++;
                    cursor_pos++;
                }
                else {
                    c_code[i] = ccat_code[cursor_pos];
                    i++;
                    cursor_pos++;
                }
            }
            c_code[i] = ')';
            i++;
            c_code[i] = ';';
            i++;
            cursor_pos++;
        }
        else {
            c_code[i] = ccat_code[cursor_pos];
            i++;
            cursor_pos++;
        }
    }

    printf("The translated C code is:\n%s", c_code);

    return 0;
}