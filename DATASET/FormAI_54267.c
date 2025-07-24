//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: excited
//Welcome to the Subnet Calculator!
//If you're ready to calculate subnets, then I'm your guy!
//I know you're pumped, so let's dive right into it!

#include <stdio.h>
#include <math.h>

int main() {
    int ipAddress[4], subnetMask[4], prefix;
    printf("Enter the IP address with dots separating each octet (e.g. 192.168.1.1): ");
    scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);
    printf("Enter the subnet mask with dots separating each octet (e.g. 255.255.255.0): ");
    scanf("%d.%d.%d.%d", &subnetMask[0], &subnetMask[1], &subnetMask[2], &subnetMask[3]);

    int i, subnet[4];
    for (i=0; i<4; i++) {
        subnet[i] = ipAddress[i] & subnetMask[i];
    }

    int numHosts = pow(2, (32 - prefix)) - 2;
    printf("Number of hosts per subnet: %d\n", numHosts);
    printf("Network address: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);

    //I hope you're having as much fun as I am!
    return 0;
}
//That's it! Hope you enjoyed using my subnet calculator!