//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 100

typedef struct {
    char* key;
    char* value;
} ResumeEntry;

int parseResume(char* fileName, ResumeEntry* entries) {
    FILE* fp;
    size_t len = 0;
    ssize_t read;
    char* line = NULL;
    int entryCount = 0;

    fp = fopen(fileName, "r");

    if (fp == NULL) {
        printf("Error opening file: %s\n", fileName);
        return -1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char* key = strtok(line, ":");
        char* value = strtok(NULL, ":");

        if (key != NULL && value != NULL) {
            entries[entryCount].key = malloc(strlen(key) + 1);
            entries[entryCount].value = malloc(strlen(value) + 1);

            strcpy(entries[entryCount].key, key);
            strcpy(entries[entryCount].value, value);

            entryCount++;
        }
    }

    fclose(fp);
    if (line)
        free(line);
    return entryCount;
}

void printResume(ResumeEntry* entries, int entryCount) {
    for (int i = 0; i < entryCount; i++) {
        printf("%s: %s\n", entries[i].key, entries[i].value);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <resume file>\n", argv[0]);
        return 1;
    }

    ResumeEntry entries[MAX_LINES];
    int entryCount = parseResume(argv[1], entries);

    printf("Found %d entries in resume:\n\n", entryCount);
    printResume(entries, entryCount);

    for (int i = 0; i < entryCount; i++) {
        free(entries[i].key);
        free(entries[i].value);
    }

    return 0;
}