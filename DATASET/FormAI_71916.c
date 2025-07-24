//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

int main()
{
    time_t current_time;
    char* c_time_string;
    int mem_total, mem_free;
    struct sysinfo info;

    while(1)
    {
        sleep(1);
        sysinfo(&info);
        mem_total = (int)(info.totalram/1024/1024);
        mem_free = (int)(info.freeram/1024/1024);

        // Get the current time.
        current_time = time(NULL);
 
        // Convert it to local time format.
        c_time_string = ctime(&current_time);
 
        // Print the current time and RAM usage.
        printf("%sTotal RAM: %d MB\tFree RAM: %d MB\n", c_time_string, mem_total, mem_free);
       
    }
    return 0;
}