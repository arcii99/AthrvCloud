//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    struct timeval prevUser, prevSys, currUser, currSys;
    getrusage(RUSAGE_SELF, &usage);
    prevUser = usage.ru_utime;
    prevSys = usage.ru_stime;
    int count = 0;
    
    while (1) {
        // calculate CPU usage difference since last measurement
        getrusage(RUSAGE_SELF, &usage);
        currUser = usage.ru_utime;
        currSys = usage.ru_stime;
        double userDiff = (double)(currUser.tv_sec - prevUser.tv_sec) + (double)(currUser.tv_usec - prevUser.tv_usec) / 1000000;
        double sysDiff = (double)(currSys.tv_sec - prevSys.tv_sec) + (double)(currSys.tv_usec - prevSys.tv_usec) / 1000000;
        
        // print CPU usage difference
        printf("CPU usage in the last second:\n");
        printf("User CPU Time: %.2f seconds\n", userDiff);
        printf("System CPU Time: %.2f seconds\n\n", sysDiff);
        
        // update previous CPU usage value
        prevUser = currUser;
        prevSys = currSys;
        count++;
        
        // wait for a second before taking next measurement
        sleep(1);
        
        // quit after 50 measurements
        if (count >= 50) {
            break;
        }
    }
    return 0;
}