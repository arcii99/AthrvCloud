//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 256

struct subnet {
    char* ip_addr;
    char* binary;
    int mask;
    char* network_addr;
    char* first_host;
    char* last_host;
    char* broadcast_addr;
};

void parse_ip_address(const char* ip, int* oct1, int* oct2, int* oct3, int* oct4) {
    sscanf(ip, "%d.%d.%d.%d", oct1, oct2, oct3, oct4);
}

char* to_binary(int n, int num_bits) {
    char* bin = (char*) malloc(num_bits + 1);
    bin[num_bits] = '\0';
    for (int i = num_bits - 1; i >= 0; i--) {
        bin[i] = ((n & 1) == 1) ? '1' : '0';
        n >>= 1;
    }
    return bin;
}

char* subnet_mask(int mask_bits) {
    char* netmask = (char*) malloc(16);
    sprintf(netmask, "%d.%d.%d.%d", (int) pow(2, 8 - mask_bits), (int) pow(2, 8 - mask_bits), (int) pow(2, 8 - mask_bits), (int) pow(2, 8 - mask_bits));
    return netmask;
}

void calculate_subnet(struct subnet* s, const char* ip, int mask) {
    int oct1, oct2, oct3, oct4;
    parse_ip_address(ip, &oct1, &oct2, &oct3, &oct4);
    s->ip_addr = (char*) malloc(strlen(ip) + 1);
    strcpy(s->ip_addr, ip);
    s->binary = (char*) malloc(32 + 1);
    sprintf(s->binary, "%s.%s.%s.%s", to_binary(oct1, 8), to_binary(oct2, 8), to_binary(oct3, 8), to_binary(oct4, 8));
    s->mask = mask;
    s->network_addr = (char*) malloc(16);
    sprintf(s->network_addr, "%d.%d.%d.%d", oct1 & ((int) pow(2, mask) - 1), oct2 & ((int) pow(2, mask) - 1), oct3 & ((int) pow(2, mask) - 1), oct4 & ((int) pow(2, mask) - 1));
    s->first_host = (char*) malloc(16);
    sprintf(s->first_host, "%d.%d.%d.%d", oct1 & ((int) pow(2, mask) - 1), oct2 & ((int) pow(2, mask) - 1), oct3 & ((int) pow(2, mask) - 1), (oct4 & ((int) pow(2, mask) - 1)) + 1);
    s->last_host = (char*) malloc(16);
    sprintf(s->last_host, "%d.%d.%d.%d", (oct1 | ((int) pow(2, 8 - mask) - 1)), (oct2 | ((int) pow(2, 8 - mask) - 1)), (oct3 | ((int) pow(2, 8 - mask) - 1)), ((oct4 | ((int) pow(2, 8 - mask) - 1)) - 1));
    s->broadcast_addr = (char*) malloc(16);
    sprintf(s->broadcast_addr, "%d.%d.%d.%d", (oct1 | ((int) pow(2, 8 - mask) - 1)), (oct2 | ((int) pow(2, 8 - mask) - 1)), (oct3 | ((int) pow(2, 8 - mask) - 1)), (oct4 | ((int) pow(2, 8 - mask) - 1)));
}

int main() {
    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);
    struct subnet subnets[MAX_SUBNETS];
    char ip_address[16];
    int mask_bits;
    for (int i = 0; i < num_subnets; i++) {
        printf("\nEnter IP address for Subnet %d (e.g. 192.168.1.0): ", i + 1);
        scanf("%s", ip_address);
        printf("Enter subnet mask in bits (e.g. 24): ");
        scanf("%d", &mask_bits);
        calculate_subnet(&subnets[i], ip_address, mask_bits);
    }
    printf("\n\n");
    printf("%-20s %-20s %-20s %-20s %-20s %-20s\n", "IP Address", "Binary", "Subnet Mask", "Network Address", "First Host", "Last Host", "Broadcast Address");
    for (int i = 0; i < num_subnets; i++) {
        printf("%-20s %-20s %-20s %-20s %-20s %-20s\n", subnets[i].ip_addr, subnets[i].binary, subnet_mask(subnets[i].mask), subnets[i].network_addr, subnets[i].first_host, subnets[i].last_host, subnets[i].broadcast_addr);
    }
    printf("\n");
    return 0;
}