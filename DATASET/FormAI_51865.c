//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        exit(1);
    }

    char buf[BUF_SIZE];
    char status_path[BUF_SIZE];
    int fd;
    ssize_t num_read;
    unsigned long utime, stime;
    unsigned long long total_time;

    snprintf(status_path, BUF_SIZE, "/proc/%s/status", argv[1]);

    while(1) {
        if ((fd = open(status_path, O_RDONLY)) == -1) {
            printf("Error opening status file.\n");
            exit(1);
        }

        while((num_read = read(fd, buf, BUF_SIZE)) > 0) {
            buf[num_read] = '\0';

            if (sscanf(buf, "utime:\t%lu", &utime) == 1) {
                total_time += utime;
            }
            else if (sscanf(buf, "stime:\t%lu", &stime) == 1) {
                total_time += stime;
                break;
            }
        }

        close(fd);

        printf("CPU usage for PID %s: %llu\n", argv[1], total_time);

        sleep(1);
    }

    return 0;
}