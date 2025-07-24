//FormAI DATASET v1.0 Category: System event logger ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(const char* message) {
    time_t now;
    struct tm* timeInfo;
    char buffer[80];
    time(&now);
    timeInfo = localtime(&now);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeInfo);
    FILE *fp = fopen("system_log.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "[%s] %s\n", buffer, message);
        fclose(fp);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an event message.\n");
        return 1;
    }
    char* message = (char*) malloc(sizeof(char) * (strlen(argv[1]) + 1));
    strcpy(message, argv[1]);
    logEvent(message);
    printf("Event logged.\n");
    free(message);
    return 0;
}