//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //For sleep() function

#define MAX_LENGTH 256

int main()
{
    FILE* fp;
    char path[MAX_LENGTH];
    char mem_total[MAX_LENGTH], mem_free[MAX_LENGTH];
    long total_mem, free_mem, used_mem;

    while(1) {
        // Read the /proc/meminfo file to get the memory usage stats
        fp = popen("cat /proc/meminfo | grep MemTotal | awk '{print $2}'", "r");
        fgets(mem_total, MAX_LENGTH, fp);
        pclose(fp);
        fp = popen("cat /proc/meminfo | grep MemFree | awk '{print $2}'", "r");
        fgets(mem_free, MAX_LENGTH, fp);
        pclose(fp);

        // Convert the string values to integers
        total_mem = atol(mem_total);
        free_mem = atol(mem_free);
        used_mem = total_mem - free_mem;

        // Print the memory usage stats
        printf("RAM Usage Statistics:\n");
        printf("Total Memory: %ld kB\n", total_mem);
        printf("Used Memory: %ld kB\n", used_mem);
        printf("Free Memory: %ld kB\n", free_mem);
        printf("---------------------------------------------\n");

        sleep(5); //Sleep for 5 seconds before getting the next memory usage stats
    }

    return 0;
}