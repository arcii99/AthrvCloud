//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){

    // set variables
    long numSec = 0;
    int i = 0;
    double loadavg;
    char time_char[50];

    // loop and calculate CPU usage
    while (i < 10){
        
        // read CPU load from /proc/loadavg
        FILE *fp = fopen("/proc/loadavg", "r");
        fscanf(fp, "%lf", &loadavg);
        fclose(fp);

        // get current time
        time_t current_time = time(NULL);
        strftime(time_char, sizeof(time_char), "%Y-%m-%d %H:%M:%S", localtime(&current_time));
        
        // print CPU usage and time
        printf("Time: %s, CPU Load: %.2f%%\n", time_char, loadavg * 100.0);

        // sleep for 1 second
        sleep(1);
        i++;
    }
    return 0;
}