//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;
    size_t size;

    pid = getpid();
    size = getpagesize();

    printf("Process ID: %d\n", pid);
    printf("Page size: %zd bytes\n", size);
    printf("-------------------------------------\n");

    while(1) {
        // Get the resident set size of the current process (in bytes)
        long rss = 0;
        FILE* fp = NULL;
        if ((fp = fopen("/proc/self/statm", "r")) == NULL)
            exit(1);
        if (fscanf(fp, "%*s%ld", &rss) != 1)
            exit(1);
        fclose(fp);

        printf("RAM usage: %ld bytes\n", rss * size);
        
        sleep(1); // Wait for a second before checking the RAM usage again
    }

    return 0;
}