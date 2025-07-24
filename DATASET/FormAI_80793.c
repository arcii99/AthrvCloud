//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    struct timeval tv;

    while(1) {
        if (getrusage(RUSAGE_SELF, &usage) == -1)
            printf("Error: Could not get resource usage\n");
        else {
            tv = usage.ru_utime;
            printf("User CPU usage: %ld.%lds\n", tv.tv_sec, tv.tv_usec);
            
            tv = usage.ru_stime; 
            printf("System CPU usage: %ld.%lds\n", tv.tv_sec, tv.tv_usec);
            
            printf("Memory usage: %ld KB\n", usage.ru_maxrss);
        }

        sleep(1); // Wait 1 second before checking usage again
    }

    return 0;
}