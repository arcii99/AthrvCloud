//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_IP_LEN 16
#define MAX_SUBNET_LEN 3

// Function to validate IP address
bool is_valid_ip(char *ip_address) {
    int dot_count = 0;

    for (int i = 0; ip_address[i]; i++) {
        if (ip_address[i] == '.') {
            dot_count++;
        }
        else if (ip_address[i] < '0' || ip_address[i] > '9') {
            return false;
        }
    }

    if (dot_count != 3) {
        return false;
    }

    char *token = strtok(ip_address, ".");
    while (token != NULL) {
        int value = atoi(token);
        if (value < 0 || value > 255) {
            return false;
        }
        token = strtok(NULL, ".");
    }

    return true;
}

// Function to validate subnet mask
bool is_valid_subnet(char *subnet_mask) {
    int subnet = atoi(subnet_mask);
    if (subnet < 0 || subnet > 32) {
        return false;
    }
    return true;
}

// Function to calculate subnet
char* calculate_subnet(char *ip_address, char *subnet_mask) {
    int subnet = atoi(subnet_mask);
    char *subnet_bits = (char*) malloc(33);
    char *subnet_address = (char*) malloc(MAX_IP_LEN + 1);

    // Set subnet bits
    for (int i = 0; i < subnet; i++) {
        subnet_bits[i] = '1';
    }
    subnet_bits[subnet] = '\0';

    // Pad subnet bits with zeros
    for (int i = subnet; i < 32; i++) {
        subnet_bits[i] = '0';
    }
    subnet_bits[32] = '\0';

    // Calculate subnet address
    int subnet_octet1 = atoi(strtok(ip_address, "."));
    int subnet_octet2 = atoi(strtok(NULL, "."));
    int subnet_octet3 = atoi(strtok(NULL, "."));
    int subnet_octet4 = atoi(strtok(NULL, "."));

    subnet_octet1 = subnet_octet1 & atoi(strtok(subnet_bits, "1"));
    subnet_octet2 = subnet_octet2 & atoi(strtok(NULL, "1"));
    subnet_octet3 = subnet_octet3 & atoi(strtok(NULL, "1"));
    subnet_octet4 = subnet_octet4 & atoi(strtok(NULL, "1"));

    snprintf(subnet_address, MAX_IP_LEN + 1, "%d.%d.%d.%d", subnet_octet1, subnet_octet2, 
                                                                    subnet_octet3, subnet_octet4);
    return subnet_address;
}

// Main function
int main() {
    char ip_address[MAX_IP_LEN];
    char subnet_mask[MAX_SUBNET_LEN];

    // Get user input
    printf("Enter an IP address: ");
    fgets(ip_address, MAX_IP_LEN, stdin);
    ip_address[strcspn(ip_address, "\n")] = 0;

    printf("Enter a subnet mask (0-32): ");
    fgets(subnet_mask, MAX_SUBNET_LEN, stdin);
    subnet_mask[strcspn(subnet_mask, "\n")] = 0;

    // Validate user input
    if (!is_valid_ip(ip_address)) {
        printf("Invalid IP address\n");
    }
    else if (!is_valid_subnet(subnet_mask)) {
        printf("Invalid subnet mask\n");
    }
    else {
        // Calculate subnet
        char *subnet_address = calculate_subnet(ip_address, subnet_mask);
        printf("Subnet address for %s/%s is %s\n", ip_address, subnet_mask, subnet_address);

        // Free memory
        free(subnet_address);
    }

    return 0;
}