//FormAI DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *string, int count) {
    if (*string) {
        char curr = *string;
        int i = 0;
        char *temp = malloc(count * sizeof(char));
        while (*string == curr) {
            i++;
            string++;
        }
        sprintf(temp, "%d", i);
        strncat(temp, &curr, 1);
        printf("%s", temp);
        free(temp);
        compress(string, count-i);
    }
}

int main() {
    char *input = "XXXXYYYYYZZXXXXXXXWWW";
    int count = strlen(input);
    compress(input, count);
    return 0;
}