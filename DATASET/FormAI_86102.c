//FormAI DATASET v1.0 Category: Log analysis ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINES 1000
#define MAX_LOG_LENGTH 100

int main() {
    char logs[MAX_LOG_LINES][MAX_LOG_LENGTH];
    char c;
    int i = 0, j = 0, k = 0;
    int num_lines = 0, num_errors = 0, num_warnings = 0;
    char **errors = NULL, **warnings = NULL;

    FILE *fp = fopen("logfile.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // read the contents of the file
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            logs[i][j] = '\0';
            i++;
            j = 0;
        }
        else {
            logs[i][j] = c;
            j++;
        }
    }
    num_lines = i;

    fclose(fp);

    // search for errors and warnings
    for (i = 0; i < num_lines; i++) {
        if (strstr(logs[i], "ERROR")) {
            num_errors++;
            errors = (char**)realloc(errors, num_errors * sizeof(char*));
            errors[num_errors-1] = (char*)calloc(MAX_LOG_LENGTH, sizeof(char));
            strcpy(errors[num_errors-1], logs[i]);
        }
        else if (strstr(logs[i], "WARNING")) {
            num_warnings++;
            warnings = (char**)realloc(warnings, num_warnings * sizeof(char*));
            warnings[num_warnings-1] = (char*)calloc(MAX_LOG_LENGTH, sizeof(char));
            strcpy(warnings[num_warnings-1], logs[i]);
        }
    }

    // print out the results
    printf("Number of lines: %d\n", num_lines);
    printf("Number of errors: %d\n", num_errors);
    for (i = 0; i < num_errors; i++) {
        printf("\t%s\n", errors[i]);
    }
    printf("Number of warnings: %d\n", num_warnings);
    for (i = 0; i < num_warnings; i++) {
        printf("\t%s\n", warnings[i]);
    }

    // free memory
    for (i = 0; i < num_errors; i++) {
        free(errors[i]);
    }
    free(errors);
    for (i = 0; i < num_warnings; i++) {
        free(warnings[i]);
    }
    free(warnings);

    return 0;
}