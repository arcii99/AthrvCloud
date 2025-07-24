//FormAI DATASET v1.0 Category: Log analysis ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_KEYWORDS 3

int main(int argc, char* argv[]) {
    char searchKeywords[MAX_KEYWORDS][16] = {"ERROR", "WARNING", "FATAL"};
    int keywordCount[MAX_KEYWORDS] = {0};
    char *line;

    if (argc < 2) {
        printf("Error: No log file specified.\n");
        exit(1);
    }

    FILE *logFile = fopen(argv[1], "r");
    if (!logFile) {
        printf("Error: Log file not found.\n");
        exit(1);
    }

    while (!feof(logFile)) {
        line = fgets((char*)malloc(MAX_LINE_LENGTH), MAX_LINE_LENGTH, logFile);
        if(line) {
            for(int i = 0; i < MAX_KEYWORDS; i++) {
                if(strstr(line, searchKeywords[i])) {
                    keywordCount[i]++;
                }
            }
            free(line);
        }
    }
    fclose(logFile);

    printf("Keyword analysis of %s:\n", argv[1]);
    for(int i = 0; i < MAX_KEYWORDS; i++) {
        printf("%s: %d\n", searchKeywords[i], keywordCount[i]);
    }

    return 0;
}