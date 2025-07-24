//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_NETWORK_SIZE 3 // Maximum size of network ID in dotted decimal notation

//IP Address structure
typedef struct {
    unsigned char octet1;
    unsigned char octet2;
    unsigned char octet3;
    unsigned char octet4;
} IP;

//Subnet structure
typedef struct {
    IP network_id; // Network ID in dotted decimal notation
    unsigned int prefix_length; // Prefix length
} Subnet;

// Function to convert IP address from dotted decimal notation to binary
void ip_address_to_binary(IP ip, unsigned int *binary) {
    binary[0] = ip.octet1;
    binary[1] = ip.octet2;
    binary[2] = ip.octet3;
    binary[3] = ip.octet4;
}

// Function to convert binary IP address to dotted decimal notation
void binary_to_ip_address(unsigned int *binary, IP *ip) {
    ip->octet1 = binary[0];
    ip->octet2 = binary[1];
    ip->octet3 = binary[2];
    ip->octet4 = binary[3];
}

// Function to get subnet mask in binary
void get_subnet_mask(unsigned int prefix_length, unsigned int *mask) {
    unsigned int i = 0;
    for(i = 0; i < 4; i++) {
        if(prefix_length > 7) {
            mask[i] = 255;
            prefix_length -= 8;
        } else if(prefix_length > 0) {
            mask[i] = pow(2, 8 - prefix_length) - 1;
            prefix_length = 0;
        } else {
            mask[i] = 0;
        }
    }
}

// Function to get network ID in binary
void get_network_id(unsigned int *ip_binary, unsigned int *mask, unsigned int *network_id) {
    unsigned int i = 0;
    for(i = 0; i < 4; i++) {
        network_id[i] = ip_binary[i] & mask[i];
    }
}

// Function to get the subnet with the given prefix length of an IP address
Subnet calculate_subnet(IP ip, unsigned int prefix_length) {
    Subnet subnet;
    subnet.prefix_length = prefix_length;
    unsigned int ip_binary[4] = {0};
    unsigned int mask[4] = {0};
    unsigned int network_id[4] = {0};
    ip_address_to_binary(ip, ip_binary);
    get_subnet_mask(prefix_length, mask);
    get_network_id(ip_binary, mask, network_id);
    binary_to_ip_address(network_id, &subnet.network_id);
    return subnet;
}

// Main function
int main() {
    IP ip;
    unsigned int prefix_length;
    printf("Enter an IP address in dotted decimal notation: ");
    scanf("%hhu.%hhu.%hhu.%hhu", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4);
    printf("Enter the prefix length: ");
    scanf("%u", &prefix_length);
    Subnet subnet = calculate_subnet(ip, prefix_length);
    char network[MAX_NETWORK_SIZE];
    sprintf(network, "%hhu.%hhu.%hhu.%hhu/%u", subnet.network_id.octet1, subnet.network_id.octet2, subnet.network_id.octet3, subnet.network_id.octet4, subnet.prefix_length);
    printf("Network ID: %s\n", network);
    return 0;
}