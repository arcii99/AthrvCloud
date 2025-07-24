//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/time.h>
#include<sys/resource.h>

void print_cpu_usage(){
    // getrusage() gets the resource usage of the calling process
    struct rusage usage;
    if(getrusage(RUSAGE_SELF, &usage) != 0){
        printf("Error: Could not get CPU usage.\n");
        return;
    }
    // Convert the timeval structure to double 
    double user_time = (double)usage.ru_utime.tv_sec + ((double)usage.ru_utime.tv_usec / (double)1000000);
    printf("User CPU time: %.2f sec\n", user_time);
    
    double system_time = (double)usage.ru_stime.tv_sec + ((double)usage.ru_stime.tv_usec / (double)1000000);
    printf("System CPU time: %.2f sec\n", system_time);
    
    double total_cpu_time = user_time + system_time;
    printf("Total CPU time: %.2f sec\n\n", total_cpu_time);

    sleep(1); // wait for 1 second
    print_cpu_usage(); // recursively print CPU usage
}

int main(){
    printf("Starting CPU usage monitor. Press ctrl+C to stop.\n");
    print_cpu_usage(); // call the print_cpu_usage function recursively
    return 0;
}