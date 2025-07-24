//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main(){
    int prevRamUsage = 0;
    int currRamUsage = 0;
    int changeInRam = 0;

    printf("Monitor your C program's RAM usage!\n");

    while(1){
        char command[50];
        sprintf(command, "/proc/%d/status", getpid());
        FILE* file = fopen(command, "r");

        char line[128];

        while(fgets(line, 128, file) != NULL){
            if(strncmp(line, "VmRSS:", 6) == 0){
                currRamUsage = atoi(line + 7);
            }
        }

        fclose(file);

        if(prevRamUsage != 0){
            changeInRam = currRamUsage - prevRamUsage;
            printf("Current RAM usage: %dKB | Change from previous: %dKB\n", currRamUsage, changeInRam);
        }else{
            printf("Current RAM usage: %dKB\n", currRamUsage);
        }

        prevRamUsage = currRamUsage;

        sleep(1);
    }

    return 0;
}