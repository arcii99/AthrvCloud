//FormAI DATASET v1.0 Category: System boot optimizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MILLION 1000000L

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds * CLOCKS_PER_SEC / MILLION);
}

int main() {
    printf("Welcome to the System Boot Optimizer\n");
    printf("Initiating system startup...\n");
    delay(5000);
    
    printf("Checking for startup programs...\n");
    delay(3000);
    
    printf("Analyzing system files...\n");
    delay(4000);
    
    printf("Running disk cleanup...\n");
    delay(2000);
    
    printf("Optimizing system registry...\n");
    delay(6000);
    
    printf("Running malware scan...\n");
    delay(7000);
    
    printf("Rebooting system...\n");
    delay(5000);
    
    printf("System optimization complete!\n");
    return 0;
}