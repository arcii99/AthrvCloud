//FormAI DATASET v1.0 Category: Log analysis ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000
#define MAX_ERRORS 50

int main(int argc, char **argv) {
    FILE *file;
    char log_line[MAX_LENGTH];
    int errors = 0;
    float error_rate;

    if (argc != 2) {
        printf("Usage: %s <logfile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Analyzing log file %s...\n", argv[1]);

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(log_line, MAX_LENGTH, file) != NULL) {
        if (strstr(log_line, "ERROR") != NULL) {
            errors++;
        }
    }

    error_rate = (float) errors / (float) MAX_ERRORS;

    printf("Found %d errors in the log file.\n", errors);
    printf("Error rate is %.2f%%.\n", error_rate * 100);

    fclose(file);

    return 0;
}