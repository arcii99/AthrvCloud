//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define INTERVAL 1

// function to get the RAM usage
void get_ram_usage() {
    struct sysinfo info;
    unsigned long totalram, freeram;
    int used_ram_percentage;

    sysinfo(&info); // gets RAM information

    totalram = info.totalram * info.mem_unit;
    freeram = info.freeram * info.mem_unit;

    used_ram_percentage = (int)((totalram - freeram) * 100 / totalram); // calculate used memory percentage

    printf("Total RAM: %lu MB\n", totalram / 1024 / 1024);
    printf("Free RAM : %lu MB\n", freeram / 1024 / 1024);
    printf("Used RAM : %d %%\n", used_ram_percentage);
}

int main() {
    printf("Started RAM usage monitor\n");

    while(1) {
        get_ram_usage(); // call function

        sleep(INTERVAL); // sleep for 1 second
        system("clear"); // clear console
    }

    return 0;
}