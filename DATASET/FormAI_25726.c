//FormAI DATASET v1.0 Category: System boot optimizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a given string has only digits
bool is_digits(const char *str)
{
    while (*str)
    {
        if (*str < '0' || *str > '9')
            return false;
        
        str++;
    }
    
    return true;
}

int main()
{
    // Welcome message
    printf("Welcome to the C System Boot Optimizer!\n");
    
    // Prompt the user for the system boot time
    char boot_time[10];
    while (true)
    {
        printf("Please enter the current system boot time (in seconds): ");
        fgets(boot_time, 10, stdin);
        
        // Check if the input is valid (i.e. contains only digits)
        if (is_digits(boot_time))
            break;
        
        printf("Error: Invalid input! Please enter a valid number.\n");
    }
    
    // Convert the input to an integer
    int boot_time_int = atoi(boot_time);
    
    // Perform boot optimization based on the system boot time
    if (boot_time_int < 10)
    {
        printf("Your system is already running optimally!\n");
    }
    else if (boot_time_int < 30)
    {
        printf("Your system can benefit from some boot optimization.\n");
        printf("Optimizing...");
        // Perform optimization here
        printf("Done!\n");
    }
    else
    {
        printf("Your system is in dire need of boot optimization!\n");
        printf("Optimizing...");
        // Perform optimization here
        printf("Done!\n");
    }
    
    return 0;
}