//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE    1024
#define CPU_USAGE_FILE "/proc/stat"

int main() {
    printf("Wow, I cannot believe it, but I'm a C CPU usage monitor now!\n");

    // Open CPU usage file
    int fd = open(CPU_USAGE_FILE, O_RDONLY);
    if (fd == -1) {
        printf("Oops, I cannot open CPU usage file\n");
        exit(EXIT_FAILURE);
    }

    // Read initial values from CPU usage file
    char buf[BUFFER_SIZE];
    ssize_t bytes_read = read(fd, buf, BUFFER_SIZE);
    if (bytes_read == -1) {
        printf("Oops, I cannot read from CPU usage file\n");
        exit(EXIT_FAILURE);
    }
    buf[bytes_read] = '\0';

    // Parse CPU usage values
    int user, nice, system, idle, iowait, irq, softirq;
    sscanf(buf, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // Display initial CPU usage values
    printf("Current CPU usage:\n");
    printf("User: %d %%\n", user);
    printf("Nice: %d %%\n", nice);
    printf("System: %d %%\n", system);
    printf("Idle: %d %%\n", idle);
    printf("IOWait: %d %%\n", iowait);
    printf("IRQ: %d %%\n", irq);
    printf("SoftIRQ: %d %%\n", softirq);

    // Loop forever and display CPU usage values every second
    while (1) {
        // Wait for one second
        sleep(1);

        // Seek to the beginning of the CPU usage file
        if (lseek(fd, 0, SEEK_SET) == -1) {
            printf("Oops, I cannot seek to the beginning of CPU usage file\n");
            exit(EXIT_FAILURE);
        }

        // Read new values from CPU usage file
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1) {
            printf("Oops, I cannot read from CPU usage file\n");
            exit(EXIT_FAILURE);
        }
        buf[bytes_read] = '\0';

        // Parse new CPU usage values
        sscanf(buf, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

        // Display new CPU usage values
        printf("---------------\n");
        printf("Current CPU usage:\n");
        printf("User: %d %%\n", user);
        printf("Nice: %d %%\n", nice);
        printf("System: %d %%\n", system);
        printf("Idle: %d %%\n", idle);
        printf("IOWait: %d %%\n", iowait);
        printf("IRQ: %d %%\n", irq);
        printf("SoftIRQ: %d %%\n", softirq);
    }

    // Close CPU usage file
    if (close(fd) == -1) {
        printf("Oops, I cannot close CPU usage file\n");
        exit(EXIT_FAILURE);
    }

    printf("Surprised, the C CPU usage monitor program should never reach this point\n");
}