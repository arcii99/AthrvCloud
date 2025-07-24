//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    printf("Welcome to the CPU Usage Monitor\n\n");
    printf("Press Ctrl+C to exit\n\n");
    
    while(1)
    {
        char cmd[50] = "top -b -n 1 | grep 'Cpu(s)' | awk '{print $2 + $4}'";
        FILE *top_output = popen(cmd, "r");
        float cpu_usage;
        fscanf(top_output, "%f", &cpu_usage);
        pclose(top_output);
        
        printf("Current CPU Usage: %.2f%%\n", cpu_usage);
        sleep(1);
    }
    
    return 0;
}