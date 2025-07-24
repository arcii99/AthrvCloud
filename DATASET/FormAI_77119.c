//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert IP address to binary
void ipToBinary(char *ip, char *bin){
    int i = 0;
    char *token = strtok(ip, ".");
    while(token != NULL){
        int num = atoi(token); // convert IP octet from string to int
        for(int j = 7; j >= 0; j--){
            bin[i] = (num >> j) & 1 ? '1' : '0'; // convert each octet into binary
            i++;
        }
        token = strtok(NULL, ".");
    }
    bin[i] = '\0';
}

// function to calculate subnet mask based on CIDR notation
void cidrToMask(char cidr, char *mask){
    int num = (int)cidr - 48; // convert char to int
    for(int i = 0; i < 32; i++){
        if(i < num){
            mask[i] = '1'; // set first num bits to 1
        } else {
            mask[i] = '0'; // set the rest of the bits to 0
        }
    }
    mask[32] = '\0';
}

int main(){
    char ip[15];
    char subnet[3];
    printf("Enter IP Address (ex. 192.168.0.1): ");
    fgets(ip, 15, stdin);
    printf("Enter Subnet (ex. 24): ");
    fgets(subnet, 3, stdin);

    char binaryIp[33];
    ipToBinary(ip, binaryIp);
    printf("IP in Binary: %s\n", binaryIp);

    char subnetMask[33];
    cidrToMask(subnet[0], subnetMask);
    printf("Subnet Mask: %s\n", subnetMask);

    int numHostBits = 32 - atoi(subnet); // calculate number of host bits
    int numHosts = 1;
    for(int i = 0; i < numHostBits; i++){
        numHosts *= 2; // calculate number of hosts based on number of host bits
    }
    numHosts -= 2; // subtract 2 for network and broadcast addresses
    printf("Number of Valid Hosts: %d\n", numHosts);

    char networkAddress[33];
    for(int i = 0; i < 32; i++){
        networkAddress[i] = (binaryIp[i] == '1' && subnetMask[i] == '1') ? '1' : '0'; // calculate network address based on IP and subnet mask
    }
    networkAddress[32] = '\0';
    printf("Network Address: %s\n", networkAddress);

    char broadcastAddress[33];
    for(int i = 0; i < 32; i++){
        broadcastAddress[i] = (binaryIp[i] == '1' || subnetMask[i] == '0') ? '1' : '0'; // calculate broadcast address based on IP and subnet mask
    }
    broadcastAddress[32] = '\0';
    printf("Broadcast Address: %s\n", broadcastAddress);

    return 0;
}