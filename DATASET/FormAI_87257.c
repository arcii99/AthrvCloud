//FormAI DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int getRandomNumber(int lower, int upper){
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main(){
    printf("Welcome to C System Boot Optimizer!\n");

    printf("Scanning your system...\n");
    int storage = getRandomNumber(100, 500);
    int ram = getRandomNumber(2, 16);
    int cores = getRandomNumber(2, 8);

    printf("Your system has %dGB storage, %dGB RAM and %d cores.\n", storage, ram, cores);

    printf("Analyzing system boot performance...\n");
    int bootTime = getRandomNumber(30, 120);

    printf("Your system takes %d seconds to boot.\n", bootTime);

    printf("Optimizing...\n");
    if(storage >= 250 && ram >= 8 && cores >= 4 && bootTime <= 60){
        printf("Your system is already optimal. No further actions required.\n");
    }
    else{
        if(storage < 250){
            printf("Upgrading storage...\n");
            storage = 500;
        }
        if(ram < 8){
            printf("Upgrading RAM...\n");
            ram = 16;
        }
        if(cores < 4){
            printf("Upgrading processor...\n");
            cores = 8;
        }
        if(bootTime > 60){
            printf("Removing unnecessary applications from startup...\n");
            bootTime = getRandomNumber(20, 50);
        }
        printf("Congratulations! Your system is now optimized for boot performance.\n");
        printf("Your system now has %dGB storage, %dGB RAM and %d cores.\n", storage, ram, cores);
        printf("Your system now boots in %d seconds.\n", bootTime);
    }

    return 0;
}