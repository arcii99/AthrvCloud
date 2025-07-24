//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char *mem_usage_command = "cat /proc/meminfo | grep MemFree | awk '{print $2}'";
    char mem_usage_string[10];
    int mem_usage;
    FILE *mem_usage_file;
    
    while(1)
    {
        mem_usage_file = popen(mem_usage_command, "r");
        fgets(mem_usage_string, 10, mem_usage_file);
        mem_usage = atoi(mem_usage_string);

        printf("Current RAM usage: %d kB\n", 1024 - mem_usage);
        
        if(mem_usage <= 50)
        {
            printf("Warning! RAM usage is getting low.\n");
        }
        
        pclose(mem_usage_file);
        
        sleep(5);
    }
    
    return 0;
}