//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ip1, ip2, ip3, ip4, submask; // declaring the required variables
    char choice;

    do{
        printf("Enter the IP address in format xxx.xxx.xxx.xxx: \n");
        scanf("%d.%d.%d.%d", &ip1, &ip2, &ip3, &ip4); // reading the IP address from the user
        printf("Enter the Subnet mask in cidr format: \n");
        scanf("%d", &submask); // reading the subnet mask from the user

        if(submask < 0 || submask > 32)
        {
            printf("Invalid subnet mask! Please enter a value between 0 and 32. \n"); // validating the subnet mask
            continue;
        }

        int subnetbits = 0, i;
        for(i = 0; i < submask; i++)
        {
            subnetbits |= (1 << 31 - i); // setting a bit in subnetbits corresponding to each bit in the subnet mask
        }

        int sub1 = subnetbits >> 24, sub2 = (subnetbits >> 16) & 255, sub3 = (subnetbits >> 8) & 255, sub4 = subnetbits & 255;
        // splitting the subnet mask into its four octets

        int net1 = ip1 & sub1, net2 = ip2 & sub2, net3 = ip3 & sub3, net4 = ip4 & sub4;
        // calculating the network address by performing bitwise AND operation on each octet of IP address and subnet mask

        printf("The Network address is: %d.%d.%d.%d \n", net1, net2, net3, net4);

        int host1 = 255 - sub1, host2 = 255 - sub2, host3 = 255 - sub3, host4 = 255 - sub4;
        // calculating the number of bits available for host by subtracting subnet mask bits from 8 in each octet

        printf("The number of available host bits: %d.%d.%d.%d \n", host1, host2, host3, host4);

        printf("Do you want to calculate for another subnet? (y/n) \n");
        scanf(" %c", &choice); // asking the user if they want to calculate for another subnet

    } while(choice == 'y' || choice == 'Y'); // loop until the user says no
    
    return 0;
}