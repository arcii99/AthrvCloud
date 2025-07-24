//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert IP address from string format to integer format
unsigned long int convert_ip_to_int(char *ip_address) {
    unsigned long int ip_int = 0;
    int octet_count = 3; // index of the last octet
    char *octet = strtok(ip_address, ".");

    while (octet != NULL) {
        int octet_int = atoi(octet);
        ip_int |= (octet_int << (8 * octet_count)); // shift octet left by 8*(3-index) bits and OR with previous parts
        octet_count--;
        octet = strtok(NULL, ".");
    }

    return ip_int;
}

// function to convert IP address from integer format to string format
void convert_int_to_ip(unsigned long int ip_int, char *ip_address) {
    sprintf(ip_address, "%lu.%lu.%lu.%lu", (ip_int>>24)&0xff, (ip_int>>16)&0xff, (ip_int>>8)&0xff, ip_int&0xff);
}

// function to print binary representation of a number
void print_binary(unsigned long int num) {
    if (num > 1) {
        print_binary(num >> 1);
    }
    printf("%d", num & 1);
}

int main() {
    char ip_address[15];
    char subnet_mask[15];
    unsigned long int ip_int, subnet_mask_int, network_address_int, broadcast_address_int;
    char network_address[15], broadcast_address[15];

    printf("Enter IP address in dotted decimal format: ");
    fgets(ip_address, 15, stdin); // read input from user
    ip_address[strcspn(ip_address, "\n")] = '\0'; // remove trailing newline character
    ip_int = convert_ip_to_int(ip_address);
    printf("IP address in binary: ");
    print_binary(ip_int);
    printf("\n");

    printf("Enter subnet mask in dotted decimal format: ");
    fgets(subnet_mask, 15, stdin); // read input from user
    subnet_mask[strcspn(subnet_mask, "\n")] = '\0'; // remove trailing newline character
    subnet_mask_int = convert_ip_to_int(subnet_mask);
    printf("Subnet mask in binary: ");
    print_binary(subnet_mask_int);
    printf("\n");

    // calculate network address by ANDing IP address with subnet mask
    network_address_int = ip_int & subnet_mask_int;
    convert_int_to_ip(network_address_int, network_address);
    printf("Network address: %s\n", network_address);

    // calculate broadcast address by ORing IP address with inverse subnet mask
    broadcast_address_int = ip_int | (~subnet_mask_int);
    convert_int_to_ip(broadcast_address_int, broadcast_address);
    printf("Broadcast address: %s\n", broadcast_address);

    return 0;
}