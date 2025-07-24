//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<signal.h>
#define CPU_USAGE_BUFFER_SIZE 1024

void sigint_handler(int signal_number);

int main()
{
    signal(SIGINT, sigint_handler);

    char cpu_usage_buffer[CPU_USAGE_BUFFER_SIZE];
    memset(cpu_usage_buffer,0,CPU_USAGE_BUFFER_SIZE);

    int file_descriptor = open("/proc/stat", O_RDONLY);
    if(file_descriptor == -1)
    {
        printf("Error opening /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    unsigned long long last_total_jiffies = 0;
    unsigned long long last_idle_jiffies = 0;
    unsigned long long current_total_jiffies = 0;
    unsigned long long current_idle_jiffies = 0;

    while(1)
    {
        lseek(file_descriptor,0,SEEK_SET);
        ssize_t read_characters = read(file_descriptor,cpu_usage_buffer,CPU_USAGE_BUFFER_SIZE-1);
        if(read_characters == -1)
        {
            printf("Error reading /proc/stat\n");
            exit(EXIT_FAILURE);
        }
        cpu_usage_buffer[read_characters] = 0;
    
        char* first_token = strtok(cpu_usage_buffer," \n");
        unsigned long long user_jiffies = 0;
        unsigned long long system_jiffies = 0;
        unsigned long long idle_jiffies = 0;
        unsigned long long iowait_jiffies = 0;
        unsigned long long irq_jiffies = 0;
        unsigned long long softirq_jiffies = 0;
        unsigned long long steal_jiffies = 0;
        
        int jiffy_count = 0;
        while(first_token != NULL)
        {
            first_token = strtok(NULL," \n");
            if(first_token != NULL)
            {
                jiffy_count++;
                switch(jiffy_count)
                {
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 6:
                    case 7:
                    case 8:
                        if(jiffy_count == 4)
                        {
                            iowait_jiffies += strtoull(first_token,NULL,10);
                        }
                        else
                        {
                            user_jiffies += strtoull(first_token,NULL,10);
                        }
                        break;
                    case 5:
                        idle_jiffies += strtoull(first_token,NULL,10);
                        break;
                    case 9:
                        system_jiffies += strtoull(first_token,NULL,10);
                        break;
                    case 10:
                        irq_jiffies += strtoull(first_token,NULL,10);
                        break;
                    case 11:
                        softirq_jiffies += strtoull(first_token,NULL,10);
                        break;
                    case 12:
                        steal_jiffies += strtoull(first_token,NULL,10);
                        break;
                    default:
                        break;
                }
            }
        }
    
        current_idle_jiffies = idle_jiffies + iowait_jiffies;
        current_total_jiffies = user_jiffies + system_jiffies + current_idle_jiffies + irq_jiffies + softirq_jiffies + steal_jiffies;
        double usage = 0.0;
        if(last_total_jiffies != 0 && last_idle_jiffies != 0)
        {
            unsigned long long idle_delta = current_idle_jiffies - last_idle_jiffies;
            unsigned long long total_delta = current_total_jiffies - last_total_jiffies;
            usage = (double)(total_delta - idle_delta) / total_delta * 100.0;
        }
        
        printf("CPU usage: %f%%\n", usage);
        last_total_jiffies = current_total_jiffies;
        last_idle_jiffies = current_idle_jiffies;

        sleep(1);
    }

    return 0;
}

void sigint_handler(int signal_number)
{
    printf("\nReceived interrupt signal. Terminating...\n");
    exit(signal_number);
}