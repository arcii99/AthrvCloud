//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

void printProgressBar(int current, int max) {
    const int barWidth = 50;
    float progress = (float)current / (float)max;

    printf("[");
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) printf("=");
        else if (i == pos) printf(">");
        else printf(" ");
    }
    printf("] %d%%\r", (int)(progress * 100));
    fflush(stdout);
}

int main() {
    printf("Starting C RAM usage monitor...\n");
    struct sysinfo info;
    while (1) {
        sysinfo(&info);
        long totalram = (long)info.totalram * (long)info.mem_unit / 1024 / 1024;
        long freeram = (long)info.freeram * (long)info.mem_unit / 1024 / 1024;
        long usedram = totalram - freeram;

        printf("Total RAM: %ld MB\n", totalram);
        printf("Free RAM: %ld MB\n", freeram);
        printProgressBar(usedram, totalram);

        sleep(1);
        system("clear");
    }
    return 0;
}