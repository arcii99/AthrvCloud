//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main()
{
    struct sysinfo si;

    while (1)
    {
        sysinfo(&si);
        printf("CPU usage: %ld%%\n", (si.loads[0] / (double)(1 << SI_LOAD_SHIFT)) * 100);
        sleep(1);
    }

    return 0;
}