//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_CHARS 100

int main() {
    struct sysinfo info;
    long long freeram;
    char buffer[MAX_CHARS];

    while (1) { // continuously monitor the RAM usage
        if (sysinfo(&info) == -1) { // check if sysinfo function returns -1 (error)
            perror("sysinfo");
            exit(EXIT_FAILURE);
        }

        freeram = (long long)info.freeram * info.mem_unit; // total free RAM in bytes
        snprintf(buffer, MAX_CHARS, "Free RAM: %lld KB\n", freeram / 1024); // format the output

        printf("%s", buffer); // print the output to console
        sleep(1); // wait for 1 second before checking again
    }

    return 0;
}