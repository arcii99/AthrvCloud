//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define USED     0
#define UNUSED   1

/* get the total amount of RAM */
long get_total_ram() {
    struct sysinfo info;
    sysinfo(&info);
    return info.totalram;
}

/* get the amount of free RAM */
long get_free_ram() {
    struct sysinfo info;
    sysinfo(&info);
    return info.freeram;
}

/* monitor the RAM usage */
void monitor_ram() {
    long total_ram = get_total_ram();
    printf("Total RAM: %ld\n", total_ram);
    
    while (1) {
        long free_ram = get_free_ram();
        long used_ram = total_ram - free_ram;
        
        char usage[20];
        double percentage = ((double) used_ram / total_ram) * 100;
        snprintf(usage, sizeof(usage), "%.2f%%", percentage);
        
        /* clear the console and print the usage percentage */
        system("clear");
        printf("Used RAM: %ld\n", used_ram);
        printf("Free RAM: %ld\n", free_ram);
        printf("Usage: %s\n", usage);
        
        /* sleep for a second */
        sleep(1);
    }
}

int main() {
    monitor_ram();
    return 0;
}