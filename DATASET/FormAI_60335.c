//FormAI DATASET v1.0 Category: HTML beautifier ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    printf("Enter the name of the HTML file to beautify: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file %s.", filename);
        exit(1);
    }
    char line[500];
    while(fgets(line, 500, fp)) {
        int indent_level = 0;
        for(int i = 0; i < strlen(line); i++) {
            if(line[i] == '<') {
                printf("%*s", indent_level*4, "");
                printf("<");
                if(line[i+1] != '/') {
                    indent_level += 1;
                }
                printf("\n");
            } else if(line[i] == '>') {
                printf(">\n");
                if(line[i-1] != '/') {
                    indent_level -= 1;
                }
                printf("%*s", indent_level*4, "");
            } else {
                printf("%c", line[i]);
            }
        }
    }
    fclose(fp);
    return 0;
}