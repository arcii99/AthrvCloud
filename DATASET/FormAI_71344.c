//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LENGTH 15
#define MAX_MASK_LENGTH 2

int get_bit_value(int ip_octet, int bit_pos) {
    return (ip_octet & (1 << bit_pos)) >> bit_pos;
}

void calculate_subnet(char* ip_address, char* subnet_mask) {
    int subnet_mask_int = atoi(subnet_mask);
    int num_subnet_bits = subnet_mask_int;
    int num_host_bits = 32 - subnet_mask_int;

    char* ip_octet_str = strtok(ip_address, ".");
    int ip_octet_int = 0, cur_bit_pos = 7;
    int ip_octets[4];
    while (ip_octet_str != NULL) {
        ip_octet_int = atoi(ip_octet_str);
        for (int i = cur_bit_pos; i >= 0; i--) {
            ip_octets[3 - cur_bit_pos / 8] += get_bit_value(ip_octet_int, i) * pow(2, (cur_bit_pos % 8));
            cur_bit_pos--;
        }
        cur_bit_pos = 7;
        ip_octet_str = strtok(NULL, ".");
    }

    int num_subnet_octets = (num_subnet_bits % 8 == 0) ? (num_subnet_bits / 8) :
        (num_subnet_bits / 8 + 1);
    int num_host_octets = (num_host_bits % 8 == 0) ? (num_host_bits / 8) :
        (num_host_bits / 8 + 1);

    int subnet_mask_octets[4] = {0};
    for (int i = 0; i < num_subnet_octets; i++) {
        if (num_subnet_bits >= 8) {
            subnet_mask_octets[i] = 255;
            num_subnet_bits -= 8;
        }
        else {
            subnet_mask_octets[i] = pow(2, num_subnet_bits) - 1;
            num_subnet_bits = 0;
        }
    }

    int host_mask_octets[4] = {0};
    for (int i = 0; i < num_host_octets; i++) {
        if (num_host_bits >= 8) {
            host_mask_octets[i] = 255;
            num_host_bits -= 8;
        }
        else {
            host_mask_octets[i] = pow(2, num_host_bits) - 1;
            num_host_bits = 0;
        }
    }

    int subnet_octets[4] = {0};
    for (int i = 0; i < 4; i++) {
        subnet_octets[i] = ip_octets[i] & subnet_mask_octets[i];
    }

    int first_host_octets[4] = {0};
    memcpy(first_host_octets, subnet_octets, 4);
    first_host_octets[3] += 1;

    int last_host_octets[4] = {0};
    for (int i = 0; i < 4; i++) {
        if (i < num_subnet_octets) {
            last_host_octets[i] = subnet_octets[i];
        }
        else {
            last_host_octets[i] = 255;
        }
    }
    last_host_octets[3] -= 1;

    int broadcast_octets[4] = {0};
    for (int i = 0; i < 4; i++) {
        if (i < num_subnet_octets) {
            broadcast_octets[i] = subnet_octets[i];
        }
        else {
            broadcast_octets[i] = 255;
        }
    }

    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Binary Subnet Mask: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", subnet_mask_octets[i]);
        if (i != 3) {
            printf(".");
        }
    }
    printf("\n");
    printf("Network Address: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", subnet_octets[i]);
        if (i != 3) {
            printf(".");
        }
    }
    printf("\n");
    printf("First Usable Host Address: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", first_host_octets[i]);
        if (i != 3) {
            printf(".");
        }
    }
    printf("\n");
    printf("Last Usable Host Address: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", last_host_octets[i]);
        if (i != 3) {
            printf(".");
        }
    }
    printf("\n");
    printf("Broadcast Address: ");
    for (int i = 0; i < 4; i++) {
        printf("%d", broadcast_octets[i]);
        if (i != 3) {
            printf(".");
        }
    }
    printf("\n");
}

int main() {
    char ip_address[MAX_IP_LENGTH + 1];
    char subnet_mask[MAX_MASK_LENGTH + 1];

    printf("Enter IP Address: ");
    fgets(ip_address, sizeof(ip_address), stdin);
    ip_address[strcspn(ip_address, "\n")] = '\0';

    printf("Enter Subnet Mask: ");
    fgets(subnet_mask, sizeof(subnet_mask), stdin);
    subnet_mask[strcspn(subnet_mask, "\n")] = '\0';

    calculate_subnet(ip_address, subnet_mask);

    return 0;
}