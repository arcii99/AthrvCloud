//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main(){
    printf("CPU Usage Monitor\n");

    int i, j, k, val;
    time_t t;
    struct sysinfo info;

    for(i=0; i<10; i++){ //monitor for 10 seconds
        sysinfo(&info);
        val = (100-((info.loads[0]*100)/info.loads[1])); //calculate CPU usage
        printf("CPU Usage: %d%%\n", val);
        for(j=0; j<100000000; j++){} //delay to simulate CPU usage
        sleep(1); //wait 1 second before checking CPU usage again
    }

    printf("Monitoring complete!\n");

    return 0;
}