//FormAI DATASET v1.0 Category: HTML beautifier ; Style: retro
#include <stdio.h>

int main(void) {
    char code[5000];
    printf("Enter the HTML code to beautify:\n");
    scanf("%[^\n]", code);

    int tab_count = 0;
    int i = 0;

    while (code[i]) {
        if (code[i] == '<') {
            if (code[i+1] == '/') {
                tab_count--;
            }
            for (int j = 0; j < tab_count; j++) {
                printf("\t");
            }
            printf("%c", code[i]);
            if (code[i+1] != '/') {
                tab_count++;
            }
        }
        else if (code[i] == '>') {
            printf("%c\n", code[i]);
        }
        else {
            printf("%c", code[i]);
        }
        i++;
    }

    return 0;
}