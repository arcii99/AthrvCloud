//FormAI DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int i, j, len;

    printf("Enter a string: ");
    scanf("%s", text);

    len = strlen(text);

    for (i = 0; i < len; i++) {
        for (j = 0; j < i; j++)
            printf(" ");

        for (j = i; j < len; j++)
            printf("%c", text[j]);

        printf("\n");
    }

    return 0;
}