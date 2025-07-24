//FormAI DATASET v1.0 Category: System administration ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int signo)
{
    if (signo == SIGINT)
    {
        printf("Received SIGINT. Shutdown process initiated.\n");
        // Add your system shutdown command here
        system("shutdown -h now");
    }
}

int main()
{
    printf("System Administration Example Program\n");
    printf("-------------------------------------\n");
    printf("Press CTRL+C to Shutdown the System.\n");
    
    // Registering the signal handler function
    if (signal(SIGINT, sig_handler) == SIG_ERR)
    {
        printf("SIGINT registration failed.\n");
        exit(1);
    }
    
    // Infinite loop to keep the program running
    while(1)
    {
        printf("Program running...\n");
        sleep(1);
    }
    
    return 0;
}