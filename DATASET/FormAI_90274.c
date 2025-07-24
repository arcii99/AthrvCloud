//FormAI DATASET v1.0 Category: System boot optimizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initializing random number generator with current time
    
    // Generating random numbers between 0 and 10 to simulate boot time
    int startup_time = rand() % 11;
    int service_time = rand() % 11;
    int login_time = rand() % 11;
    
    printf("Welcome to System Boot Optimizer!\n");
    printf("Analyzing boot process...\n");
    printf("Estimated startup time: %d seconds\n", startup_time);
    printf("Optimizing services...\n");
    printf("Estimated service time: %d seconds\n", service_time);
    printf("Optimizng login process...\n");
    printf("Estimated login time: %d seconds\n", login_time);
    
    int total_time = startup_time + service_time + login_time;
    
    printf("Estimated total boot time: %d seconds\n", total_time);
    
    // Checking if total boot time is less than 30 seconds
    if(total_time < 30)
    {
        printf("Your system is now optimized for faster boot!\n");
    }
    else
    {
        printf("Your system could benefit from further optimization.\n");
    }
    
    return 0;
}