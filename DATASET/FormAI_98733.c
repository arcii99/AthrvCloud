//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <string.h>

void firewall(char *ip_address, int port) {
    if (port > 1024) {
        printf("Firewall blocking access to port %d on IP address %s.\n", port, ip_address);
        return;
    }

    if (strcmp(ip_address, "127.0.0.1") == 0) {
        printf("Access granted to local host.\n");
        return;
    }

    if (strcmp(ip_address, "192.168.0.1") == 0) {
        printf("Access granted to private network.\n");
        return;
    }

    if (strcmp(ip_address, "10.0.0.1") == 0) {
        printf("Access granted to corporate network.\n");
        return;
    }

    printf("Firewall blocking access to IP address %s. Contact network administrator for further assistance.\n", ip_address);
}

int main() {
    char ip_address[16];
    int port;

    printf("Enter IP address: ");
    scanf("%s", ip_address);

    printf("Enter port number: ");
    scanf("%d", &port);

    firewall(ip_address, port);

    return 0;
}