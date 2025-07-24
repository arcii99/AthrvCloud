//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void monitor_RAM_usage(int counter)
{
    char str[20];
    FILE* fp;
    int ram_usage;

    sprintf(str, "/proc/%d/statm", getpid());
    fp = fopen(str, "r");
    fscanf(fp, "%d", &ram_usage);
    fclose(fp);

    printf("RAM usage: %d\n", ram_usage);

    counter++;

    if(counter < 10)
    {
        sleep(1);
        monitor_RAM_usage(counter);
    }
}

int main()
{
    monitor_RAM_usage(0);
    return 0;
}