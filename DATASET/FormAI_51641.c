//FormAI DATASET v1.0 Category: Log analysis ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_FILE_PATH "log.txt"

int main(void) {
    FILE *log_file = fopen(LOG_FILE_PATH, "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[256];
    int num_warning = 0, num_error = 0, num_fatal = 0;

    while (fgets(line, sizeof(line), log_file)) {
        if (strstr(line, "WARNING")) {
            num_warning++;
        } else if (strstr(line, "ERROR")) {
            num_error++;
        } else if (strstr(line, "FATAL")) {
            num_fatal++;
        }
    }

    printf("Number of warnings: %d\n", num_warning);
    printf("Number of errors: %d\n", num_error);
    printf("Number of fatals: %d\n", num_fatal);

    fclose(log_file);
    return 0;
}