//FormAI DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <string.h>

void recursiveLogParser(FILE *fp, char *line) {
    if (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, "ERROR") != NULL) {
            printf("Error Found: %s", line);
        }
        recursiveLogParser(fp, line);
    }
}

int main() {
    FILE *fp;
    char filename[] = "serverlog.txt";
    char line[256];

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s", filename);
        return 1;
    }

    recursiveLogParser(fp, line);

    fclose(fp);
    return 0;
}