//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {

    while(1){
        struct sysinfo info;
        sysinfo(&info);

        long totalram = (long) info.totalram * (long) info.mem_unit / 1024 / 1024;
        long freeram = (long) info.freeram * (long) info.mem_unit / 1024 / 1024;
        long usedram = totalram - freeram;
        float ramusage = usedram * 100.0 / totalram;

        printf("Total RAM: %ld MB, Free RAM: %ld MB, Used RAM: %ld MB, RAM Usage: %.2f %%\n",
               totalram, freeram, usedram, ramusage);

        sleep(1);
    }

    return 0;
}