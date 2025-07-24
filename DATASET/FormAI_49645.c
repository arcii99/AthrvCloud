//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<ifaddrs.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
    struct ifaddrs *ifAddrStruct = NULL;
    void *tmpAddrPtr = NULL;

    printf("Starting C Wireless Network Scanner ...\n\n");

    // Get all address information of host
    getifaddrs(&ifAddrStruct);

    // Search for wireless network interfaces
    while(ifAddrStruct != NULL)
    {
        // Check if the address is IPv4 and wireless network
        if(ifAddrStruct->ifa_addr->sa_family == AF_INET &&
           strstr(ifAddrStruct->ifa_name,"wlan") != NULL) 
        {
            tmpAddrPtr=&((struct sockaddr_in *)ifAddrStruct->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);

            printf("Wireless Network Interface Found: %s -> %s\n",ifAddrStruct->ifa_name,addressBuffer);
        }

        ifAddrStruct = ifAddrStruct->ifa_next;
    }

    // Free memory
    freeifaddrs(ifAddrStruct);

    printf("\nC Wireless Network Scanner terminated\n");

    return 0;
}