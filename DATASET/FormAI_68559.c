//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(){
    printf("Welcome to the surrealist CPU usage monitor!\n");
    printf("Press enter key to begin monitoring.\n");

    while(getchar()){
        int cpu_usage = rand() % 101;

        printf("The CPU is currently %d%% utilized.\n", cpu_usage);

        if(cpu_usage > 50){
            printf("Be careful, the CPU is overheating and might cause surrealistic effects...\n");
        }

        time_t now;
        time(&now);

        printf("Monitoring initiated at %s", ctime(&now));
    }
}