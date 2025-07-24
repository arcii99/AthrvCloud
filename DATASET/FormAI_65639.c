//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <time.h>

int main()
{
    while(1)
    {
        system("top -b -n 1 | grep 'Cpu(s):' | sed 's/.*, *\([0-9.]*\)%* id.*/\1/' > /tmp/cpu_usage");
        FILE* file = fopen("/proc/meminfo", "r");
        char line[256];
        int total_mem, free_mem;
        while(fgets(line, sizeof(line), file)){
            if(sscanf(line, "MemTotal: %d kB", &total_mem) == 1){
                printf("Total Memory: %d kB\n", total_mem);
            }
            else if(sscanf(line, "MemFree: %d kB", &free_mem) == 1){
                printf("Free Memory: %d kB\n", free_mem);
            }
        }
        fclose(file);
        double cpu_usage, mem_usage;
        FILE* cpu_file = fopen("/tmp/cpu_usage", "r");
        fscanf(cpu_file, "%lf", &cpu_usage);
        fclose(cpu_file);
        mem_usage = ((double)(total_mem - free_mem) / total_mem) * 100;
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        printf("Memory Usage: %.2f%%\n", mem_usage);
        printf("-------------------------------\n");
        sleep(1);
    }
    return 0;
}