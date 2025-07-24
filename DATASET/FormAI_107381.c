//FormAI DATASET v1.0 Category: Log analysis ; Style: funny
#include <stdio.h>

int main() {
    char logFile[] = "funny_log.log";
    FILE* file = fopen(logFile, "r");
    int success = 0, error = 0, warning = 0, total = 0;
    char line[256];
    char message[256];
    while (fgets(line, sizeof line, file)) {
        total++;
        switch (line[0]) {
            case 'S':
                success++;
                break;
            case 'E':
                error++;
                sscanf(line, "%*s %*s %[^\n]", message);
                printf("Oh no, an error occurred: %s\n", message);
                break;
            case 'W':
                warning++;
                sscanf(line, "%*s %*s %[^\n]", message);
                printf("Warning! %s\n", message);
                break;
            default:
                printf("What is this? %s", line);
        }
    }
    printf("Total log entries: %d\n", total);
    printf("Successes: %d\n", success);
    printf("Errors: %d\n", error);
    printf("Warnings: %d\n", warning);
    printf("Looks like everything is under control\n");
    return 0;
}