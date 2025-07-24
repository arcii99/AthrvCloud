//FormAI DATASET v1.0 Category: Firewall ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the IP address is valid or not
int isValidIpAddress(char *ipAddress)
{
    // Splitting the IP address into tokens using strtok() function
    char *token = strtok(ipAddress, ".");
    int num, count = 0;

    // Looping over all the tokens
    while (token != NULL)
    {
        num = atoi(token); // Converting the string token into integer
        if (num >= 0 && num <= 255)
        {
            token = strtok(NULL, ".");
            count++;
        }
        else
        {
            return 0;
        }
    }

    // Checking if the number of tokens is 4 or not
    if (count == 4)
        return 1;

    return 0;
}

int main()
{
    char ipAddress[20];

    printf("Enter the IP address: ");
    fgets(ipAddress, 20, stdin);

    // Removing the newline character from the IP address
    ipAddress[strcspn(ipAddress, "\n")] = 0;

    if (isValidIpAddress(ipAddress))
        printf("The IP address %s is valid.\n", ipAddress);
    else
        printf("The IP address %s is invalid.\n", ipAddress);

    return 0;
}