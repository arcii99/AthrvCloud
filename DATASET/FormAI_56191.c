//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BITMASK_24 0x00FFFFFF
#define BITMASK_16 0x0000FFFF

typedef struct {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
} IP4_Address;

typedef struct {
    IP4_Address network_address;
    IP4_Address broadcast_address;
    IP4_Address first_host;
    IP4_Address last_host;
    int total_hosts;
    int prefix_length;
    int subnet_mask;
} Subnet;

int convert_to_bitmask(int prefix_length) {
    if (prefix_length >= 24) {
        return 0xFFFFFFFF;
    } else if (prefix_length >= 16) {
        return (BITMASK_24 << (prefix_length - 24));
    } else {
        return (BITMASK_16 << (prefix_length - 8));
    }
}

void print_address(IP4_Address address) {
    printf("%d.%d.%d.%d\n", address.a, address.b, address.c, address.d);
}

void print_subnet(Subnet subnet) {
    printf("Network Address: ");
    print_address(subnet.network_address);
    printf("Broadcast Address: ");
    print_address(subnet.broadcast_address);
    printf("First Host: ");
    print_address(subnet.first_host);
    printf("Last Host: ");
    print_address(subnet.last_host);
    printf("Total Hosts: %d\n", subnet.total_hosts);
    printf("Prefix Length: /%d\n", subnet.prefix_length);
    printf("Subnet Mask: 0x%08X\n", subnet.subnet_mask);
}

Subnet calculate_subnet(IP4_Address address, int prefix_length) {
    Subnet subnet;
    int subnet_mask = convert_to_bitmask(prefix_length);
    int total_hosts = pow(2, (32 - prefix_length)) - 2;
    subnet.network_address.a = address.a & (subnet_mask >> 24);
    subnet.network_address.b = address.b & ((subnet_mask >> 16) & 0xFF);
    subnet.network_address.c = address.c & ((subnet_mask >> 8) & 0xFF);
    subnet.network_address.d = address.d & (subnet_mask & 0xFF);
    subnet.broadcast_address.a = subnet.network_address.a | (~subnet_mask >> 24);
    subnet.broadcast_address.b = subnet.network_address.b | ((~subnet_mask >> 16) & 0xFF);
    subnet.broadcast_address.c = subnet.network_address.c | ((~subnet_mask >> 8) & 0xFF);
    subnet.broadcast_address.d = subnet.network_address.d | (~subnet_mask & 0xFF);
    subnet.first_host.a = subnet.network_address.a;
    subnet.first_host.b = subnet.network_address.b;
    subnet.first_host.c = subnet.network_address.c;
    subnet.first_host.d = subnet.network_address.d + 1;
    subnet.last_host.a = subnet.broadcast_address.a;
    subnet.last_host.b = subnet.broadcast_address.b;
    subnet.last_host.c = subnet.broadcast_address.c;
    subnet.last_host.d = subnet.broadcast_address.d - 1;
    subnet.total_hosts = total_hosts;
    subnet.prefix_length = prefix_length;
    subnet.subnet_mask = subnet_mask;
    return subnet;
}

int main(int argc, char *argv[]) {
    char address_str[16];
    int prefix_length;
    printf("Enter IP Address: ");
    scanf("%s", address_str);
    printf("Enter Prefix Length: ");
    scanf("%d", &prefix_length);
    IP4_Address address;
    memset(&address, 0, sizeof(IP4_Address));
    sscanf(address_str, "%hhu.%hhu.%hhu.%hhu", &address.a, &address.b, &address.c, &address.d);
    Subnet subnet = calculate_subnet(address, prefix_length);
    print_subnet(subnet);
    return 0;
}