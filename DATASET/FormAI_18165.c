//FormAI DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file_pointer;
    int count_warnings = 0, count_errors = 0;

    file_pointer = fopen("log_file.txt", "r");
    if (file_pointer == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file_pointer)) {
        if (strstr(line, "WARNING")) {
            count_warnings++;
        }
        if (strstr(line, "ERROR")) {
            count_errors++;
        }
    }

    fclose(file_pointer);
    printf("The log file has %d warning(s) and %d error(s).\n", count_warnings, count_errors);

    return 0;
}