//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    char line[1000];
    while (fgets(line, sizeof(line), fp)) {
        int indent = 0;
        int i = 0;
        while (line[i] != '\0') {
            if (line[i] == '<') {
                if (line[i+1] == '/') {
                    indent--;
                }
                for (int j=0; j<indent; j++) {
                    printf("  ");
                }
                if (line[i+1] == '!') {
                    printf("%c", line[i]);
                } else {
                    printf("%c\n", line[i]);
                }
                if (line[i+1] != '/') {
                    indent++;
                }
            } else {
                for (int j=0; j<indent; j++) {
                    printf("  ");
                }
                printf("%c", line[i]);
            }
            i++;
        }
    }
    fclose(fp);
    return 0;
}