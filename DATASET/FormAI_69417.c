//FormAI DATASET v1.0 Category: Text processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *input_string(FILE *fp, size_t size) {
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char) * size); 
    if (!str) return str;
    while (EOF != (ch = fgetc(fp)) && !isspace(ch)) {
        str[len++] = ch;
        if (len == size) {
            str = realloc(str, sizeof(char) * (size += 16));
            if (!str) return str;
        }
    }
    str[len++] = '\0';

    return realloc(str, sizeof(char) * len);
}

int main() {
    printf("Enter words to invert (press enter to enter new words):\n");
    int lines = 0;
    char *input = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&input, &len, stdin)) != -1) {
        printf("Original String: %s", input);
        int i, j = strlen(input) - 1;
        if (input[j] == '\n') 
            input[j] = '\0';
        for (i = j - 1; i >= 0; i--) {
            if (isspace(input[i])) {
                printf("%s ", &input[i] + 1);
                input[i] = '\0';
            }
            if (i == 0) {
                printf("%s\n", input);
            }
        }
        lines++;
    }
    printf("Processed %d lines\n", lines);
    return 0;
}