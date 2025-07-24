//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MB 1048576

int main(void)
{
    struct sysinfo info;

    while(1)
    {
        if(sysinfo(&info) != 0)
        {
            perror("Error: Unable to retrieve system information.");
            exit(EXIT_FAILURE);
        }
        
        long long totalram = info.totalram;
        long long freeram = info.freeram;
        long long usedram = totalram - freeram;
        float used_percentage = ((float)usedram / totalram) * 100;

        printf("\n\n");
        printf("########### SYSTEM RAM USAGE MONITOR ############\n\n");
        printf("Total RAM: %lld MB\n", totalram / MB);
        printf("Used RAM: %lld MB\n", usedram / MB);
        printf("Free RAM: %lld MB\n", freeram / MB);
        printf("Used RAM Percentage: %.2f %%\n\n", used_percentage);

        sleep(5); // wait for 5 seconds before the next check
    }

    return 0;
}