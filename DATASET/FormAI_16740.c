//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
    FILE* filePointer;
    char buffer[BUFFER_SIZE];
    unsigned long long previousTotal = 0, previousIdle = 0;
    float percentage;
    while(1)
    {
        filePointer = fopen("/proc/stat", "r");
        fgets(buffer, BUFFER_SIZE, filePointer);
        fclose(filePointer);

        unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
        sscanf(buffer, "%*s %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        
        unsigned long long total = user + nice + system + idle + iowait + irq + softirq + steal;
        unsigned long long differenceIdle = idle - previousIdle;
        unsigned long long differenceTotal = total - previousTotal;
        percentage = ((float)differenceTotal - (float)differenceIdle)/(float)differenceTotal * 100;
        printf("CPU usage: %.2f%%\n", percentage);
        previousTotal = total;
        previousIdle = idle;
        sleep(1);
    }
    return 0;
}