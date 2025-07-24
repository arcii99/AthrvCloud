//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main()
{
    printf("Welcome to CPU Usage Monitor Program!\n");

    struct rusage usage;
    while(1)
    {
        int status = getrusage(RUSAGE_SELF, &usage);
        if(status == -1)
        {
            printf("Error occurred while retrieving CPU usage!\n");
            exit(-1);
        }
        printf("CPU Usage: %ld.%06ld seconds\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
        printf("Memory Usage: %ld bytes\n", usage.ru_maxrss);
        
        sleep(1);
    }
    return 0;
}