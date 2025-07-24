//FormAI DATASET v1.0 Category: Log analysis ; Style: real-life
#include <stdio.h>
#include <string.h>

#define LOG_FILE "app.log"
#define MAX_LINE_SIZE 100

int main() {

    FILE *fileptr;
    char line[MAX_LINE_SIZE];
    char key[] = "ERROR";
    int error_count = 0;

    fileptr = fopen(LOG_FILE, "r");
    if (fileptr == NULL) {
        printf("Error opening %s file.", LOG_FILE);
        return -1;
    }

    while (fgets(line, MAX_LINE_SIZE, fileptr) != NULL) {
        if (strstr(line, key) != NULL) {
            error_count++;
        }
    }

    printf("The log file %s contains %d errors.\n", LOG_FILE, error_count);

    fclose(fileptr);

    return 0;
}