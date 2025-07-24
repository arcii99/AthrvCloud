//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo sys_info; //declare a struct to store system info
    long cpu_previous_total = 0, cpu_previous_idle = 0; //initialize the variables to store previous CPU states

    while (1) { //while loop to continuously monitor the CPU usage
        if (sysinfo(&sys_info) != 0) { //get system info and check for errors
            printf("Error: could not get system info.\n");
            return 1;
        }
        
        long cpu_current_total = sys_info.totalram - sys_info.freeram; //calculate current total CPU usage
        long cpu_current_idle = sys_info.freeram; //calculate current idle CPU usage
        
        double cpu_usage = ((double)(cpu_current_total - cpu_previous_total) / (double)(cpu_current_total + cpu_current_idle - cpu_previous_total - cpu_previous_idle)) * 100.0; //calculate and print CPU usage
        
        printf("CPU Usage: %.2f%%\n", cpu_usage); 

        cpu_previous_total = cpu_current_total; //update previous CPU states
        cpu_previous_idle = cpu_current_idle;

        sleep(1); //pause program for 1 second to avoid excessive CPU usage
    }
    
    return 0;
}