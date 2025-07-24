//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/resource.h>

int main(){
    struct rusage usage;
    struct tms tm;
    clock_t start, end;
    int i = 0;
    while(1){
        if(i == 0){
            start = times(&tm);
            getrusage(RUSAGE_SELF, &usage);
            printf("CPU Usage Monitor\n");
            printf("------------------\n");
            printf("User CPU Time: %ld.%06ld s\n", tm.tms_utime/1000000, tm.tms_utime%1000000);
            printf("System CPU Time: %ld.%06ld s\n", tm.tms_stime/1000000, tm.tms_stime%1000000);
            printf("Maximum Resident Set Size: %ld MB\n", usage.ru_maxrss/1024);
            printf("------------------\n");
            i++;
        }
        end = times(&tm);
        getrusage(RUSAGE_SELF, &usage);
        printf("Current CPU Usage\n");
        printf("------------------\n");
        printf("User CPU Time: %ld.%06ld s\n", tm.tms_utime/1000000, tm.tms_utime%1000000);
        printf("System CPU Time: %ld.%06ld s\n", tm.tms_stime/1000000, tm.tms_stime%1000000);
        printf("Maximum Resident Set Size: %ld MB\n", usage.ru_maxrss/1024);
        printf("------------------\n");
        sleep(1);
    }
    return 0;
}