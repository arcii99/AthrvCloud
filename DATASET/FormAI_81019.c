//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define MAX_LENGTH 50
#define PROC_STAT "/proc/stat"

int main()
{
    int fd;
    char str[MAX_LENGTH];
    char cpu_name[MAX_LENGTH][MAX_LENGTH];
    long int clk_tck = sysconf(_SC_CLK_TCK);
    unsigned long long int prev_idle_time = 0, prev_total_time = 0;
    unsigned long long int cur_idle_time, cur_total_time, total_time_diff, idle_time_diff, cpu_usage;
    int cpu_count = 0;

    fd = open(PROC_STAT, O_RDONLY);
    read(fd, str, MAX_LENGTH);
    char *token = strtok(str, " ");
    while(token != NULL)
    {
        if(strcmp(token, "cpu") != 0)
        {
            strcpy(cpu_name[cpu_count++], token);
        }
        token = strtok(NULL, " ");
    }

    while(1)
    {
        lseek(fd, 0, SEEK_SET);
        read(fd, str, MAX_LENGTH);

        token = strtok(str, " ");
        token = strtok(NULL, " ");
        cur_total_time = 0;
        for(int i=0; i<10; i++)
        {
            token = strtok(NULL, " ");
            cur_total_time += atoll(token);
            if(i == 3)
            {
                cur_idle_time = atoll(token);
            }
        }

        total_time_diff = cur_total_time - prev_total_time;
        idle_time_diff = cur_idle_time - prev_idle_time;
        cpu_usage = (total_time_diff - idle_time_diff) * 100 / total_time_diff;

        printf("CPU Usage\n");
        for(int i=0; i<cpu_count; i++)
        {
            printf("%s: %llu%%\n", cpu_name[i], cpu_usage);
        }

        prev_idle_time = cur_idle_time;
        prev_total_time = cur_total_time;
        sleep(1);
    }

    return 0;
}