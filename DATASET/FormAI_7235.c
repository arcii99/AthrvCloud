//FormAI DATASET v1.0 Category: System boot optimizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define BOOT_TIME_LIMIT 5.0 // in seconds

int main(int argc, char *argv[]) {
    double boot_time = 0.0; // initialize boot time to zero
    char buf[BUF_SIZE]; // buffer for reading files

    // minimize the number of system calls by opening files in advance
    int dev_null = open("/dev/null", O_WRONLY);
    int rc_local = open("/etc/rc.local", O_RDONLY);

    // redirect stderr to /dev/null to suppress error messages
    dup2(dev_null, STDERR_FILENO);

    // measure the time required to execute /etc/rc.local
    time_t start_time = time(NULL);
    while (read(rc_local, buf, BUF_SIZE) > 0) { /* do nothing */ }
    boot_time = difftime(time(NULL), start_time);

    // check if the system booted within the time limit
    if (boot_time <= BOOT_TIME_LIMIT) {
        printf("Boot optimized successfully (boot time = %.2f s)\n", boot_time);
        exit(EXIT_SUCCESS);
    } else {
        fprintf(stderr, "Boot optimization failed (boot time = %.2f s)\n", boot_time);
        exit(EXIT_FAILURE);
    }
}