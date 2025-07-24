//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_DESCRIPTION_LENGTH 500

typedef struct {
    char name[MAX_LINE_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
} Metadata;

Metadata* extract_metadata(const char* filename) {
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    Metadata* metadata = (Metadata*)calloc(1, sizeof(Metadata));
    int line_number = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file \"%s\"\n", filename);
        return NULL;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        line_number++;

        if (strncmp(line, "//@", 3) == 0) {
            char* ptr = &line[3];

            while (*ptr == ' ' || *ptr == '\t') {
                ptr++;
            }

            if (*ptr == '\0') {
                printf("Warning: empty metadata line in file \"%s\", line %d\n", filename, line_number);
                continue;
            }

            if (strstr(ptr, "name") == ptr) {
                ptr += strlen("name");

                while (*ptr == ' ' || *ptr == '\t' || *ptr == ':') {
                    ptr++;
                }

                if (*ptr == '\0') {
                    printf("Error: missing name in file \"%s\", line %d\n", filename, line_number);
                    fclose(fp);
                    free(metadata);
                    return NULL;
                }

                if (snprintf(metadata->name, MAX_LINE_LENGTH, "%s", ptr) >= MAX_LINE_LENGTH) {
                    printf("Error: name too long in file \"%s\", line %d\n", filename, line_number);
                    fclose(fp);
                    free(metadata);
                    return NULL;
                }
            } else if (strstr(ptr, "description") == ptr) {
                ptr += strlen("description");

                while (*ptr == ' ' || *ptr == '\t' || *ptr == ':') {
                    ptr++;
                }

                if (*ptr == '\0') {
                    printf("Error: missing description in file \"%s\", line %d\n", filename, line_number);
                    fclose(fp);
                    free(metadata);
                    return NULL;
                }

                if (snprintf(metadata->description, MAX_DESCRIPTION_LENGTH, "%s", ptr) >= MAX_DESCRIPTION_LENGTH) {
                    printf("Error: description too long in file \"%s\", line %d\n", filename, line_number);
                    fclose(fp);
                    free(metadata);
                    return NULL;
                }
            } else {
                printf("Error: unrecognized metadata type in file \"%s\", line %d\n", filename, line_number);
                fclose(fp);
                free(metadata);
                return NULL;
            }
        }
    }

    fclose(fp);

    return metadata;
}

int main() {
    Metadata* metadata = extract_metadata("example.c");

    if (metadata != NULL) {
        printf("Metadata:\n");
        printf("  Name: %s\n", metadata->name);
        printf("  Description: %s\n", metadata->description);
        free(metadata);
    }

    return 0;
}