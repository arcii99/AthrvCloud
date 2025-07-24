//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include<stdio.h>

int main(){
    // Welcome message
    printf("Welcome to the C Subnet Calculator!\n");
    
    // Input the IP Address and Subnet mask values
    int ip[4], subnet[4];
    printf("Enter the IP Address in the format x.x.x.x: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    
    printf("Enter the Subnet Mask in the format x.x.x.x: ");
    scanf("%d.%d.%d.%d", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);
    
    // Calculate the Network Address
    int network[4];
    for(int i=0; i<4; i++){
        network[i] = ip[i] & subnet[i];
    }
    printf("\nThe Network Address is: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    
    // Calculate the Broadcast Address
    int broadcast[4];
    for(int i=0; i<4; i++){
        broadcast[i] = network[i] | (~subnet[i] & 255);
    }
    printf("The Broadcast Address is: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    
    // Calculate the Number of Hosts
    int num_hosts = 1;
    for(int i=0; i<4; i++){
        num_hosts *= subnet[i] == 255 ? 1 : 256 - subnet[i];
    }
    num_hosts -= 2;  // Subtract 2 for the Network and Broadcast Addresses
    printf("The Number of Hosts that can be connected to this Network is: %d\n", num_hosts);
    
    // Calculate the Subnet Mask in CIDR notation
    int cidr = 0;
    for(int i=0; i<4; i++){
        int temp_subnet = subnet[i];
        while(temp_subnet > 0){
            cidr += temp_subnet % 2;
            temp_subnet /= 2;
        }
    }
    printf("The Subnet Mask in CIDR notation is: /%d\n", cidr);
    
    return 0;
}