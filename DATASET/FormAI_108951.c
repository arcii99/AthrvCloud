//FormAI DATASET v1.0 Category: Temperature monitor ; Style: safe
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<signal.h>

// Function to handle the SIGINT signal
void handle_sigint(int sig)
{
    printf("\nSIGINT received\n");
    exit(0);
}

int main()
{
    // Registering the SIGINT signal handler
    signal(SIGINT, handle_sigint);
    
    float temperature;
    srand(time(NULL)); // seed the random number generator
    
    while(1)
    {
        // Generate a random temperature between -50 and 50 degrees Celsius
        temperature = ((float)rand()/(float)(RAND_MAX))*100 - 50;
        printf("Current temperature: %0.2f degrees Celsius\n", temperature);
        
        // If the temperature is below freezing, display a warning message
        if(temperature < 0)
        {
            printf("WARNING: Temperature below freezing!\n");
        }
        
        // Wait for 5 seconds before checking the temperature again
        sleep(5);
    }
    
    return 0;
}