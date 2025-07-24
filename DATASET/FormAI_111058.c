//FormAI DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome, traveler! Pray, what is thy code?\n");

    char code[1000];
    fgets(code, 1000, stdin);

    int indent = 0;
    for (int i = 0; i < strlen(code); i++) {
        char c = code[i];
        if (c == '\n') {
            printf("\n");
            continue;
        }
        if (c == '{') {
            printf("{\n");
            indent++;
            for (int j = 0; j < indent; j++) {
                printf("    ");
            }
            continue;
        }
        if (c == '}') {
            printf("\n");
            indent--;
            for (int j = 0; j < indent; j++) {
                printf("    ");
            }
            printf("}\n");
            continue;
        }
        printf("%c", c);
    }

    return 0;
}