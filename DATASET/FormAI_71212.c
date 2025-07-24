//FormAI DATASET v1.0 Category: Log analysis ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide the filename as the first argument\n");
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int total_logs = 0;
    int total_errors = 0;
    int total_warnings = 0;

    while((read = getline(&line, &len, fp)) != -1) {
        total_logs++;
        if(strstr(line, "ERROR")) {
            total_errors++;
            printf("Error: %s", line);
        } else if(strstr(line, "WARNING")) {
            total_warnings++;
            printf("Warning: %s", line);
        }
    }

    printf("\nTotal logs: %d\n", total_logs);
    printf("Total errors: %d\n", total_errors);
    printf("Total warnings: %d\n", total_warnings);

    fclose(fp);
    if(line) free(line);

    return 0;
}