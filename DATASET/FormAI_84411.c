//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

//Function to calculate subnet mask
void CalcSubnetMask(char* subnetMask, int noOfBits) {
    int subnetBits[32];
    int i = 0;
    for(i= 0; i< noOfBits; ++i) {
        subnetBits[i]= 1;
    }
    for(i= noOfBits; i< 32; ++i) {
        subnetBits[i]= 0;
    }
    sprintf(subnetMask,"%d.%d.%d.%d",subnetBits[0]*255+subnetBits[1]*127+subnetBits[2]*63+subnetBits[3]*31,
        subnetBits[4]*15+subnetBits[5]*7+subnetBits[6]*3+subnetBits[7]*1,subnetBits[8]*255+subnetBits[9]*127+subnetBits[10]*63+subnetBits[11]*31,
        subnetBits[12]*15+subnetBits[13]*7+subnetBits[14]*3+subnetBits[15]*1);
}

//Asynchronous function to get the network address and broadcast address
void GetNetworkBroadcastAddress(char* ipAddress, char* subnetMask, char* network, char *broadcast) {
    struct in_addr addr, mask, networkAddr, broadcastAddr;
    inet_aton(ipAddress,&addr);
    inet_aton(subnetMask,&mask);
    networkAddr.s_addr= addr.s_addr & mask.s_addr;
    broadcastAddr.s_addr= addr.s_addr | (~mask.s_addr);
    strcpy(network,inet_ntoa(networkAddr));
    strcpy(broadcast,inet_ntoa(broadcastAddr));  
}

int main() {
    char ipAddress[50], subnetMask[50], network[50], broadcast[50];
    int noOfBits;
    printf("Enter the IP address: ");
    scanf("%s",ipAddress);
    printf("Enter the number of bits in the subnet mask: ");
    scanf("%d",&noOfBits);
    fflush(stdin);
    CalcSubnetMask(subnetMask, noOfBits);
    GetNetworkBroadcastAddress(ipAddress, subnetMask, network, broadcast);
    printf("\nIP address: %s",ipAddress);
    printf("\nSubnet Mask: %s",subnetMask);
    printf("\nNetwork Address: %s",network);
    printf("\nBroadcast Address: %s",broadcast);
    return 0;
}