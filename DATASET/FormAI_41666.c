//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char network[20];
    char netmask[20];
    char broadcast[20];
    char first_host[20];
    char last_host[20];
} subnet_t;

void calculate_subnet(char* ip, char* mask, subnet_t* subnet) {
    // Implementation of subnet calculation algorithm
}

int main() {
    char ip[20], mask[20];
    subnet_t subnet;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter subnet mask: ");
    scanf("%s", mask);

    calculate_subnet(ip, mask, &subnet);

    printf("\nNetwork Address: %s\n", subnet.network);
    printf("Netmask: %s\n", subnet.netmask);
    printf("Broadcast Address: %s\n", subnet.broadcast);
    printf("First Host Address: %s\n", subnet.first_host);
    printf("Last Host Address: %s\n", subnet.last_host);

    return 0;
}