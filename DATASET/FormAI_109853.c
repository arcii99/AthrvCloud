//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(){
    struct rusage usage;
    long usage_size = sizeof(usage);
    int count = 1; 
    printf("Starting C RAM usage monitor... \n");
    while(1){
        if(getrusage(RUSAGE_SELF, &usage) != 0){
            printf("Error getting program usage \n");
            return 1;
        }
        printf("Iteration count : %d\n", count);
        printf("Current RAM usage : %ld KB\n", usage.ru_maxrss);
        printf("------------------------\n");
        count++;
        sleep(1); // wait for 1 second
    }
    printf("Exiting C RAM usage monitor... \n");
    return 0;
}