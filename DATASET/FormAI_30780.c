//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define SEC_TO_MICRO 1000000

int main(int argc, char *argv[]){
    printf("[INFO] Starting C RAM Usage Monitor...\n");
    
    //Get total available memory in system
    struct sysinfo sys_info;
    sysinfo(&sys_info);
    long long total_memory = sys_info.totalram;
    total_memory *= sys_info.mem_unit;
    printf("[INFO] Total memory available in system: %lld\n", total_memory);
    
    //Default check RAM usage for every 1 second
    int interval = 1;
    if(argc > 1){
        interval = atoi(argv[1]);
    }
    printf("[INFO] Checking RAM usage for every %d second(s)\n", interval);
    
    //Initiate infinite loop to check RAM usage
    while(1){
        //Get used memory by doing difference between total memory and available memory
        long long used_memory = total_memory - sys_info.freeram * sys_info.mem_unit;
        printf("[INFO] Used memory: %lld\n", used_memory);
        
        //Calculate percentage of used memory
        float percentage_used_memory = ((float)used_memory / (float)total_memory) * 100.0;
        printf("[INFO] Percentage of used memory: %.2f%%\n", percentage_used_memory);
        
        sleep(interval);
    }
    
    return 0;
}