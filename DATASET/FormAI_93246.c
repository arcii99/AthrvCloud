//FormAI DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define LOGFILE "/var/log/myapp.log"
#define BUFFER_SIZE 256

int main(int argc, char** argv)
{
    int fd;
    char buffer[BUFFER_SIZE];
    time_t rawtime;
    struct tm * timeinfo;
    char command[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: %s [command]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    snprintf(command, BUFFER_SIZE, "/bin/sh -c '%s'", argv[1]);
    system(command);

    fd = open(LOGFILE, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        printf("Failed to open logfile: %s\n", LOGFILE);
        exit(EXIT_FAILURE);
    }

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d %02d:%02d:%02d %s\n",
             timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
             timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, argv[1]);
    if (write(fd, buffer, strlen(buffer)) == -1) {
        printf("Failed to write to logfile: %s\n", LOGFILE);
    }

    close(fd);
    exit(EXIT_SUCCESS);
}