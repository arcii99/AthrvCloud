//FormAI DATASET v1.0 Category: System boot optimizer ; Style: happy
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Welcome to HappyBoot v1.0 boot optimizer!\n");
    printf("Your computer will be happier than ever before!\n");
    printf("Optimizing boot...\n");

    bool isSSD = false;
    int bootTime = 120;
    int optimizedBootTime = 70;

    // Check if the system drive is an SSD to skip unnecessary optimizations
    printf("Checking if system drive is an SSD...\n");
    // Simulating the check with a random number
    int randomNum = rand() % 2;
    if (randomNum == 0) {
        printf("No SSD detected. Performing boot optimization...\n");
    } else {
        printf("SSD detected. Skipping unnecessary optimizations.\n");
        optimizedBootTime = bootTime;
    }

    // Check if unnecessary processes are running at boot time
    printf("Checking for unnecessary processes running at boot time...\n");
    // Simulating the check with a random number
    randomNum = rand() % 2;
    if (randomNum == 0) {
        printf("No unnecessary processes detected.\n");
    } else {
        printf("Unnecessary processes detected and terminated.\n");
        optimizedBootTime -= 10;
    }

    // Check if there are any unnecessary startup programs
    printf("Checking for unnecessary startup programs...\n");
    // Simulating the check with a random number
    randomNum = rand() % 2;
    if (randomNum == 0) {
        printf("No unnecessary startup programs detected.\n");
    } else {
        printf("Unnecessary startup programs detected and disabled.\n");
        optimizedBootTime -= 20;
    }

    printf("Boot optimization complete!\n");
    printf("Your computer will now boot up %d seconds faster than before!\n", bootTime - optimizedBootTime);
    
    return 0;
}