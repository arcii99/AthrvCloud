//FormAI DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {
    char logFile[] = "/var/log/future.log";
    char searchKeyword[] = "time travel";

    FILE *file = fopen(logFile, "r");
    if (file == NULL) {
        printf("Error opening log file!\n");
        return 1;
    }

    char line[256];
    int found = 0;
    int lineNumber = 0;
    while (fgets(line, sizeof(line), file)) {
        lineNumber++;

        if (strstr(line, searchKeyword)) {
            found = 1;
            printf("Found '%s' on line %d: %s", searchKeyword, lineNumber, line);
        }
    }

    if (!found) {
        printf("Could not find '%s' in log file.\n", searchKeyword);
    }

    fclose(file);

    return 0;
}