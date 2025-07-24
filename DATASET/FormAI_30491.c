//FormAI DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables for IP Addresses
    char allowedIP[20] = "192.168.1.10";
    char blockedIP[20] = "192.168.1.100";
    
    // Declare variable for user IP input
    char userIP[20];
    
    // Start the Firewall program
    printf("Welcome to the Firewall Program!\n");
    printf("Please enter your IP Address: ");
    scanf("%s", userIP);
    
    // Check if user IP is allowed
    if(strcmp(userIP, allowedIP) == 0)
    {
        printf("Access granted! You are allowed to access the network.\n");
    }
    // Check if user IP is blocked
    else if(strcmp(userIP, blockedIP) == 0)
    {
        printf("Access denied! Your IP Address has been blocked.\n");
    }
    // If user IP is not allowed or blocked
    else
    {
        printf("Access denied! You are not allowed to access the network.\n");
    }
    
    // End the Firewall program
    printf("Thank you for using the Firewall Program!\n");
    
    return 0;
}