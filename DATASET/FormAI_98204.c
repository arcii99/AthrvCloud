//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/sysinfo.h>

int main(int argc, char* argv[]) {
    struct sysinfo si;
    int interval = 1;
    int opt;

    while ((opt = getopt(argc, argv, "i:")) != -1) {
        switch (opt) {
            case 'i':
                interval = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Usage: %s [-i interval]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    while (1) {
        if (sysinfo(&si) == -1) {
            fprintf(stderr, "Failed to get sysinfo\n");
            exit(EXIT_FAILURE);
        }

        printf("Memory usage: %ld/%ld MB (%ld%%)\n",
               (si.totalram - si.freeram) / 1024 / 1024,
               si.totalram / 1024 / 1024,
               (si.totalram - si.freeram) * 100 / si.totalram);

        sleep(interval);
    }

    return 0;
}