//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

int main()
{
    FILE *fp;
    char buffer[MAX_LINE_LENGTH];
    int spaces = 0;

    fp = fopen("input.html", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, MAX_LINE_LENGTH, fp)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '<') {
                printf("%*s%c", spaces, "", buffer[i]);
                spaces += 4;
            } else if (buffer[i] == '>') {
                printf("%c\n", buffer[i]);
                spaces -= 4;
            } else {
                printf("%c", buffer[i]);
            }
        }
    }

    fclose(fp);

    return 0;
}