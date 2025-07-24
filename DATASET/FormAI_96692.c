//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the C Subnet Calculator!\n\n");

    unsigned int ip, subnetBits;
    printf("Enter an IP address (in decimal notation): ");
    scanf("%u", &ip);

    printf("Enter the number of subnet bits: ");
    scanf("%u", &subnetBits);

    unsigned int subnetMask = ~((1 << (32 - subnetBits)) - 1);
    unsigned int networkAddress = ip & subnetMask;
    unsigned int broadcastAddress = networkAddress | ~(subnetMask);

    printf("\nSubnet mask: %u\n", subnetMask);
    printf("Network address: %u\n", networkAddress);
    printf("Broadcast address: %u\n", broadcastAddress);

    printf("\nWould you like to calculate another subnet? (y/n) ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        system("cls"); // Optional: Clear the console screen
        main(); // Recursive function call to start over
    }
    else
    {
        printf("\nThank you for using the C Subnet Calculator!\n");
    }

    return 0;
}