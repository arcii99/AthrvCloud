//FormAI DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 1000

int main(int argc, char* argv[]) {
    char* logfile = argv[1];
    char* search_string = argv[2];
    int num_lines = 0;
    char lines[MAX_LINES][MAX_CHARS_PER_LINE];

    FILE* fp;

    if ((fp = fopen(logfile, "r")) == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_CHARS_PER_LINE];

    while (fgets(line, MAX_CHARS_PER_LINE, fp) != NULL) {
        strcpy(lines[num_lines], line);
        num_lines++;
    }

    fclose(fp);

    printf("Searching for: %s\n", search_string);

    for (int i = 0; i < num_lines; i++) {
        if (strstr(lines[i], search_string) != NULL) {
            printf("Match on line %d: %s", i+1, lines[i]);
        }
    }

    return 0;
}