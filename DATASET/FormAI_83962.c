//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
 
int main(){
    int usage[10], i;
    float avg_usage, total_usage;
 
    while(1) {  
        for(i = 0; i < 10; i++){
            FILE* file = fopen("/proc/stat", "r");
            fscanf(file, "cpu %d %*d %*d %*d %*d %*d %*d", &usage[i]);
            fclose(file);
            sleep(1);
        }
 
        total_usage = 0;
        for(i = 0; i < 10; i++){
            total_usage += (float)usage[i];
        }
 
        avg_usage = total_usage/10;
 
        printf("Average CPU Usage over past 10 seconds: %.2f%%\n", avg_usage);
    }
 
    return 0;
}