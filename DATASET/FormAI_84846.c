//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    
    if (argc != 2) { // Check if IP address is provided as command-line argument
        printf("Usage: ./subnet_calculator <IP address>\n");
        return 1;
    }
    
    char *ip_address = argv[1]; // Get IP address from command-line argument
    
    char *ip_parts[4];
    char *delimiter = ".";
    char *part = strtok(ip_address, delimiter); // Split IP address into separate octets
    
    int i = 0;
    while (part != NULL && i < 4) {
        ip_parts[i++] = part;
        part = strtok(NULL, delimiter);
    }
    
    if (i != 4) { // Check if IP address is valid
        printf("Invalid IP address.\n");
        return 1;
    }
    
    int octets[4];
    for (int i = 0; i < 4; i++) {
        octets[i] = atoi(ip_parts[i]); // Convert octets from string to integer
        if (octets[i] < 0 || octets[i] > 255) { // Check if octet is valid
            printf("Invalid IP address.\n");
            return 1;
        }
    }
    
    printf("IP address: %s\n", ip_address);
    printf("CIDR notation (e.g. /24): ");
    
    int cidr;
    scanf("%d", &cidr); // Get CIDR notation from user
    
    if (cidr < 0 || cidr > 32) { // Check if CIDR notation is valid
        printf("Invalid CIDR notation.\n");
        return 1;
    }
    
    // Calculate subnet mask
    int subnet_mask[4];
    memset(subnet_mask, 0, sizeof subnet_mask);
    int bits_remainder = cidr % 8;
    int bytes_complete = cidr / 8;
    for (int i = 0; i < bytes_complete; i++) {
        subnet_mask[i] = 255;
    }
    if (bits_remainder > 0) {
        subnet_mask[bytes_complete] = (int) pow(2, bits_remainder) - 1;
    }
    
    // Calculate subnet address
    int subnet_address[4];
    for (int i = 0; i < 4; i++) {
        subnet_address[i] = octets[i] & subnet_mask[i];
    }
    
    // Calculate broadcast address
    int broadcast_address[4];
    memset(broadcast_address, 0, sizeof broadcast_address);
    bits_remainder = 8 - bits_remainder;
    if (bits_remainder == 8) {
        bytes_complete++;
    }
    for (int i = 0; i < bytes_complete; i++) {
        broadcast_address[i] = subnet_address[i];
    }
    if (bits_remainder > 0) {
        broadcast_address[bytes_complete] = (int) pow(2, bits_remainder) - 1;
    }
    for (int i = bytes_complete + 1; i < 4; i++) {
        broadcast_address[i] = 255;
    }
    
    // Print subnet information
    printf("\nSubnet mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
    printf("Subnet address: %d.%d.%d.%d\n", subnet_address[0], subnet_address[1], subnet_address[2], subnet_address[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("Number of usable host addresses: %d\n", (int) pow(2, 32 - cidr) - 2);
    
    return 0;
}