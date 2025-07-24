//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main(){
    int mb = 1024 * 1024; // define megabyte constant

    while(1){
        struct sysinfo info; // define sysinfo struct
        if(sysinfo(&info) != 0){ // get system memory statistics
            printf("Error: could not get system info\n");
            exit(EXIT_FAILURE);
        }

        double total_ram = (double)info.totalram * (double)info.mem_unit / mb; // calculate total RAM in MB
        double free_ram = (double)info.freeram * (double)info.mem_unit / mb; // calculate free RAM in MB
        double used_ram = total_ram - free_ram; // calculate used RAM in MB
        double ram_usage_percent = (used_ram / total_ram) * 100; // calculate RAM usage percentage
        
        printf("Total Memory: %.2f MB   Free Memory: %.2f MB   Used Memory: %.2f MB   RAM Usage: %.2f%%\n",
               total_ram, free_ram, used_ram, ram_usage_percent); // display statistics

        sleep(5); // wait for 5 seconds before checking RAM usage again
    }

    return 0;
}