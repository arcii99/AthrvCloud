//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TOTAL_RAM 1073741824   // 1 GB of RAM
#define PAGE_SIZE 4096         // 4 KB page size

int main() {
    int fd = open("/proc/self/statm", O_RDONLY); // open the /proc/self/statm file to read memory usage information
    if (fd == -1) {
        perror("Error opening /proc/self/statm file");
        return 1;
    }

    char buf[128];
    long int size, resident, share, text, lib, data, dt;  // variables to hold memory usage information

    printf("------------------------------\n");
    printf("RAM USAGE MONITOR\n");
    printf("------------------------------\n");

    while (1) { 
        lseek(fd, 0, SEEK_SET);   // move file offset back to the beginning of the file to read memory usage information again
        if (read(fd, buf, 128) == -1) {
            perror("Error reading /proc/self/statm file");
            return 1;
        }
        sscanf(buf, "%ld %ld %ld %ld %ld %ld %ld", &size, &resident, &share, &text, &lib, &data, &dt); // update memory usage information variables
        printf("\nTotal RAM: %d MB\n", TOTAL_RAM / (1024*1024));
        printf("RSS: %ld MB\n", resident * (PAGE_SIZE / (1024*1024))); // calculate resident memory usage in MB
        printf("Shared Memory: %ld MB\n", share * (PAGE_SIZE / (1024*1024))); // calculate shared memory usage in MB
        printf("Data + Stack: %ld MB\n", data * (PAGE_SIZE / (1024*1024))); // calculate data and stack memory usage in MB
        printf("------------------------------");

        sleep(5); // wait for 5 seconds before checking memory usage again
    }

    close(fd);
    return 0;
}