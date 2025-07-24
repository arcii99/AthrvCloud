//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *asciify(char *text);

int main() {
    char *input = (char *)calloc(256, sizeof(char));
    printf("Enter text to convert to ASCII art:\n");
    scanf("%[^\n]", input);
    char *ascii_art = asciify(input);
    printf("%s\n", ascii_art);
    free(input);
    free(ascii_art);
    return 0;
}

char *asciify(char *text) {
    char *result = (char *)calloc(1024, sizeof(char));
    char *map[] = {
        "    _    ",
        "  _( )_  ",
        " |     | ",
        " |     | ",
        " `\\_0_/''"
    };
    int len = strlen(text);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < len; j++) {
            char c = text[j];
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A';
                strcat(result, map[i] + 5*c);
            } else if (c == ' ') {
                strcat(result, "     ");
            } else {
                strcat(result, " ????? ");
            }
            strcat(result, " ");
        }
        strcat(result, "\n");
    }
    return result;
}