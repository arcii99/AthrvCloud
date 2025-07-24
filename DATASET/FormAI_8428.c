//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the structure for IP address
typedef struct {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
} ip_address;

// Define the structure for subnet mask
typedef struct {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
} subnet_mask;

// Function to validate the input IP address and subnet mask
int validate_input(ip_address ip, subnet_mask mask) {
    // Check if IP address is valid
    if (ip.octet1 < 0 || ip.octet1 > 255 ||
        ip.octet2 < 0 || ip.octet2 > 255 ||
        ip.octet3 < 0 || ip.octet3 > 255 ||
        ip.octet4 < 0 || ip.octet4 > 255) {
        printf("Invalid input: IP address is not valid.\n");
        return 0;
    }
    
    // Check if subnet mask is valid
    if (mask.octet1 < 0 || mask.octet1 > 255 ||
        mask.octet2 < 0 || mask.octet2 > 255 ||
        mask.octet3 < 0 || mask.octet3 > 255 ||
        mask.octet4 < 0 || mask.octet4 > 255) {
        printf("Invalid input: Subnet mask is not valid.\n");
        return 0;
    }
    
    // Check if subnet mask is valid using bitwise operations
    if ((mask.octet1 & mask.octet2 & mask.octet3 & mask.octet4) != 0) {
        printf("Invalid input: Subnet mask is not valid.\n");
        return 0;
    }
    
    return 1;
}

// Function to calculate the network address using bitwise operations
void calculate_network_address(ip_address ip, subnet_mask mask, int* network_address) {
    network_address[0] = ip.octet1 & mask.octet1;
    network_address[1] = ip.octet2 & mask.octet2;
    network_address[2] = ip.octet3 & mask.octet3;
    network_address[3] = ip.octet4 & mask.octet4;
}

// Function to calculate the broadcast address using bitwise operations
void calculate_broadcast_address(ip_address ip, subnet_mask mask, int* broadcast_address) {
    broadcast_address[0] = (ip.octet1 & mask.octet1) | (~mask.octet1 & 0xff);
    broadcast_address[1] = (ip.octet2 & mask.octet2) | (~mask.octet2 & 0xff);
    broadcast_address[2] = (ip.octet3 & mask.octet3) | (~mask.octet3 & 0xff);
    broadcast_address[3] = (ip.octet4 & mask.octet4) | (~mask.octet4 & 0xff);
}

// Function to calculate the number of hosts on the subnet using bitwise operations
int calculate_number_of_hosts(subnet_mask mask) {
    int bits = 0;
    bits += (mask.octet1 & 0x80) ? 1 : 0;
    bits += (mask.octet1 & 0x40) ? 1 : 0;
    bits += (mask.octet1 & 0x20) ? 1 : 0;
    bits += (mask.octet1 & 0x10) ? 1 : 0;
    bits += (mask.octet2 & 0x80) ? 1 : 0;
    bits += (mask.octet2 & 0x40) ? 1 : 0;
    bits += (mask.octet2 & 0x20) ? 1 : 0;
    bits += (mask.octet2 & 0x10) ? 1 : 0;
    bits += (mask.octet3 & 0x80) ? 1 : 0;
    bits += (mask.octet3 & 0x40) ? 1 : 0;
    bits += (mask.octet3 & 0x20) ? 1 : 0;
    bits += (mask.octet3 & 0x10) ? 1 : 0;
    bits += (mask.octet4 & 0x80) ? 1 : 0;
    bits += (mask.octet4 & 0x40) ? 1 : 0;
    bits += (mask.octet4 & 0x20) ? 1 : 0;
    bits += (mask.octet4 & 0x10) ? 1 : 0;
    return pow(2, 32 - bits) - 2; // substract network and broadcast addresses
}

// The main function that takes input, validates it, and calls the other functions to output the results
int main() {
    ip_address ip;
    subnet_mask mask;
    char input[20];
    int network_address[4];
    int broadcast_address[4];
    int number_of_hosts;
    
    printf("Please enter the IP address (e.g. 192.168.0.1): ");
    fgets(input, 20, stdin); // read input using fgets
    sscanf(input, "%d.%d.%d.%d", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4); // parse input using sscanf
    
    printf("Please enter the subnet mask (e.g. 255.255.255.0): ");
    fgets(input, 20, stdin); // read input using fgets
    sscanf(input, "%d.%d.%d.%d", &mask.octet1, &mask.octet2, &mask.octet3, &mask.octet4); // parse input using sscanf
    
    if (validate_input(ip, mask)) { // validate input
        calculate_network_address(ip, mask, network_address); // calculate network address
        calculate_broadcast_address(ip, mask, broadcast_address); // calculate broadcast address
        number_of_hosts = calculate_number_of_hosts(mask); // calculate number of hosts
        
        printf("Network address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
        printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
        printf("Number of hosts: %d\n", number_of_hosts);
    }
    
    return 0;
}