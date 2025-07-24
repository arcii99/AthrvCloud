//FormAI DATASET v1.0 Category: Firewall ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    // Check for correct usage of the program
    if (argc < 2) 
    {
        printf("Usage: %s [IP address]\n", argv[0]);
        return 1;
    }
    
    // Get the IP address from the command line arguments
    char *ip_address = argv[1];
    
    // Define the firewall rule
    char *firewall_rule = "127.0.0.1";
    
    // Compare the IP address with the firewall rule
    if (strcmp(ip_address, firewall_rule) == 0) 
    {
        printf("Access granted!\n");
    } 
    else 
    {
        printf("Access denied!\n");
    }
    
    return 0;
}