//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Generate random number
    srand(time(NULL));
    int key = rand() % 10000;
    
    // Initialize boot timer
    int boot_time = 0;
    
    printf("Welcome to the C System Boot Optimizer\n");
    printf("Your boot time is currently %d seconds\n", boot_time);
    printf("Please enter the 4-digit key to optimize your boot time:\n");
    
    int user_key;
    scanf("%d", &user_key);
    
    if(user_key == key) {
        printf("Congratulations! Your system will now be optimized for faster boot time.\n");
        printf("Please wait while the C System Boot Optimizer works its magic...\n");
        
        // Fake optimization process
        for(int i=0;i<50;i++) {
            printf("Optimizing %d%%...\n", i*2);
            sleep(1);
        }
        
        printf("Boot time optimized! Your boot time is now %d seconds.\n", boot_time - 10);
    } else {
        printf("Incorrect key entered. Optimization cancelled.");
    }
    
    return 0;
}