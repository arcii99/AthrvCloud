//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){
    struct rusage usage; // struct to store system resource usage
    int cpu_percent; // variable to store CPU usage in percentage

    while(1){
        if(getrusage(RUSAGE_SELF, &usage) == -1){ // get system resource usage
            printf("Error in getting resource usage!");
            exit(1);
        }
        
        cpu_percent = (int)((double)usage.ru_utime.tv_sec / (double)usage.ru_stime.tv_sec * 100); // calculate CPU usage in percentage

        printf("Current CPU usage: %d%%\n", cpu_percent); // display CPU usage
        
        sleep(1); // wait for 1 second
    }

    return 0;
}