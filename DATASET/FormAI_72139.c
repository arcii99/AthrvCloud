//FormAI DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void backup_file(char* filename) {
    char command[1000];
    time_t now = time(NULL);
    struct tm * timeinfo = localtime(&now);
    char timestamp[50];
    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", timeinfo);
    sprintf(command, "cp %s %s.%s", filename, filename, timestamp);
    system(command);
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        printf("Please specify a file to backup\n");
        return 0;
    }
    for(int i = 1; i < argc; i++) {
        backup_file(argv[i]);
    }
    printf("Backup complete!\n");
    return 0;
}