//FormAI DATASET v1.0 Category: System boot optimizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int bootTime = 0, optimizeTime = 0, bootCount = 0;
    srand(time(0));
    printf("Welcome to C System Boot Optimizer!\n");
    printf("How long does it take for your system to boot (in seconds)?\n");
    scanf("%d", &bootTime);
    printf("How long do you want the optimizer to run (in seconds)?\n");
    scanf("%d", &optimizeTime);
    
    while(optimizeTime > 0){
        int randomTime = rand() % 5;
        if(bootTime > 60){
            bootTime -= randomTime;
        }
        optimizeTime -= 5;
        bootCount++;
    }
    
    printf("Optimizer complete! Your system will now boot in %d seconds.\n", bootTime);
    printf("Number of boots optimized: %d\n", bootCount);
    return 0;
}