//FormAI DATASET v1.0 Category: System boot optimizer ; Style: recursive
#include <stdio.h>

int bootOptimizer(int initTime, int bootTime) {
    if(initTime == bootTime)
        return bootTime;
    if(initTime < bootTime) {
        bootTime -= initTime;
        return bootOptimizer(initTime, bootTime);
    }
    return bootTime; //return the optimized boot time
}

int main() {
    int initTime, bootTime, optimizedTime;
    printf("Enter initial boot time in seconds: ");
    scanf("%d", &initTime);
    printf("Enter current boot time in seconds: ");
    scanf("%d", &bootTime);
    optimizedTime = bootOptimizer(initTime, bootTime);
    printf("Optimized boot time is %d seconds.\n", optimizedTime);
    return 0;
}