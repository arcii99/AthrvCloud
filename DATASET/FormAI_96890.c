//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX_IP_LENGTH 16 // maximum length of an IP address string
#define MAX_REDIRECT 100 // maximum number of redirect nodes

void read_IP(char *ip_address);
void extract_octets(char *ip_address, int *octets);
int calculate_subnet(int *octets, int subnet_mask);
void print_binary(int number, int digits);

int main(void) {
    char ip_address[MAX_IP_LENGTH];
    int octets[4];
    int subnet_mask;
    int subnet_number;

    printf("Enter the IP address: ");
    read_IP(ip_address);
    extract_octets(ip_address, octets);

    printf("Enter the subnet mask (0-32): ");
    scanf("%d", &subnet_mask);

    if(subnet_mask < 0 || subnet_mask > 32) {
        printf("Invalid subnet mask value. Please try again.");
        return 0;
    }

    subnet_number = calculate_subnet(octets, subnet_mask);

    printf("The subnet number is: %d.%d.%d.%d/%d\n", octets[0], octets[1], octets[2], subnet_number, subnet_mask);

    return 0;
}

void read_IP(char *ip_address) {
    scanf("%s", ip_address);
}

void extract_octets(char *ip_address, int *octets) {
    char *token = strtok(ip_address, ".");
    int i = 0;
    while(token != NULL) {
        octets[i] = atoi(token);
        i++;
        token = strtok(NULL, ".");
    }
}

int calculate_subnet(int *octets, int subnet_mask) {
    // calculate the binary representation of the subnet mask
    int mask_binary = pow(2, subnet_mask) - 1;

    // calculate the subnet number using the AND operator
    int subnet_number = octets[3] & mask_binary;

    return subnet_number;
}

void print_binary(int number, int digits) {
    int mask = 1 << (digits - 1);
    for(int i = 0; i < digits; i++) {
        if((number & mask) != 0) {
            printf("1");
        } else {
            printf("0");
        }
        mask = mask >> 1;
    }
}