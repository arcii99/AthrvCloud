//FormAI DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

int main(int argc, char *argv[]) {
    char *filename;
    char line[256];
    char keywords[] = "hacker,attack,compromise,exploit";
    int line_count = 0;
    int keywords_count = 0;
    int i, j;

    if (argc < 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        exit(1);
    }
    else {
        filename = argv[1];
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Read lines from file
    while (fgets(line, sizeof(line), fp)) {
        line_count++;

        // Check for keywords
        for (i = 0; i < strlen(line); i++) {
            if (line[i] == ' ') {
                continue;
            }
            for (j = 0; j < strlen(keywords); j++) {
                if (line[i] == keywords[j]) {
                    keywords_count++;
                    break;
                }
            }
        }
    }

    printf("Total number of lines in log file: %d\n", line_count);
    printf("Number of lines containing keywords: %d\n", keywords_count);

    if (keywords_count > 0) {
        printf("Potential security breach detected!\n");
    }
    else {
        printf("No security breaches detected.\n");
    }

    fclose(fp);

    return 0;
}