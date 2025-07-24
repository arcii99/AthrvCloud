//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include<stdio.h>
#include<string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 100

int main() {
    FILE *fp;

    char filename[100];
    printf("Enter the CSV filename with extension: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file %s",filename);
        return 1;
    }

    char line[MAX_CHARS_PER_LINE];
    char *token;

    char lines[MAX_LINES][MAX_CHARS_PER_LINE];
    int line_count = 0;

    while(fgets(line, MAX_CHARS_PER_LINE, fp)) {
        if (line_count > MAX_LINES) {
            printf("Too many lines in file, increase MAX_LINES");
            return 1;
        }
        strcpy(lines[line_count], line);
        line_count++;
    }

    fclose(fp);

    for (int i = 0; i < line_count; i++) {
        token = strtok(lines[i], ",\n");
        while(token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, ",\n");
        }
        printf("\n");
    }

    return 0;
}