//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo info;
    long total_ram;
    double used_ram_percent;

    while(1) {
        sysinfo(&info);
        total_ram = info.totalram / 1024 / 1024; // Convert bytes to MB
        used_ram_percent = (double)(info.totalram - info.freeram) / info.totalram * 100;

        printf("Total RAM: %ld MB\n", total_ram);
        printf("Used RAM: %.2f%%\n", used_ram_percent);

        sleep(1); // Wait for 1 second
        system("clear"); // Clear the console screen
    }

    return 0; // Exit the program
}