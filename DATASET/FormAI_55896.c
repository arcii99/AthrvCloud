//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
    char inputIP[100];
    char *token;
    int dotCount=0;
    int subnet, nHosts;
    unsigned long ipAddr, subnetMask, wildcardMask;
    unsigned long networkAddr, broadcastAddr;
    char subnetMask_str[17], wildcardMask_str[17];
    printf("Enter IP Address: ");
    fgets(inputIP,100,stdin);
    token = strtok(inputIP,".");
    while(token!=NULL){
        dotCount++;
        if(dotCount==1) ipAddr = atol(token) << 24;
        if(dotCount==2) ipAddr |= atol(token) << 16;
        if(dotCount==3) ipAddr |= atol(token) << 8;
        if(dotCount==4) ipAddr |= atol(token);
        token = strtok(NULL,".");
    }
    printf("Enter Subnet Mask in CIDR Notation: ");
    scanf("%d",&subnet);
    nHosts = pow(2,32-subnet) - 2;
    subnetMask = -1 << (32-subnet);
    wildcardMask = ~subnetMask;
    networkAddr = (ipAddr & subnetMask);
    broadcastAddr = networkAddr | wildcardMask;
    sprintf(subnetMask_str,"%lu.%lu.%lu.%lu",(subnetMask & 0xFF000000)>>24,(subnetMask & 0xFF0000)>>16,(subnetMask & 0xFF00)>>8, subnetMask & 0xFF);
    sprintf(wildcardMask_str,"%lu.%lu.%lu.%lu",(wildcardMask & 0xFF000000)>>24,(wildcardMask & 0xFF0000)>>16,(wildcardMask & 0xFF00)>>8, wildcardMask & 0xFF);
    printf("\nIP Address: %lu.%lu.%lu.%lu\n", (ipAddr & 0xFF000000)>>24, (ipAddr & 0xFF0000)>>16, (ipAddr & 0xFF00)>>8, ipAddr & 0xFF);
    printf("Subnet Mask: %s\n", subnetMask_str);
    printf("WildCard Mask: %s\n", wildcardMask_str);
    printf("Network Address: %lu.%lu.%lu.%lu\n", (networkAddr & 0xFF000000)>>24, (networkAddr & 0xFF0000)>>16, (networkAddr & 0xFF00)>>8, networkAddr & 0xFF);
    printf("Broadcast Address: %lu.%lu.%lu.%lu\n", (broadcastAddr & 0xFF000000)>>24, (broadcastAddr & 0xFF0000)>>16, (broadcastAddr & 0xFF00)>>8, broadcastAddr & 0xFF);
    printf("Number of Available Hosts: %d\n", nHosts);
    return 0;
}