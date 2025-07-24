//FormAI DATASET v1.0 Category: Firewall ; Style: thoughtful
// This is a simple example of implementing a firewall in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rule {
    char source[15];
    char dest[15];
    int port;
};

int main() {
    struct rule firewall[] = {
        {"192.168.0.1", "192.168.0.2", 8080},
        {"192.168.0.3", "192.168.0.4", 443},
        {"192.168.0.2", "192.168.0.1", 8080},
        {"192.168.0.4", "192.168.0.3", 443},
    };
    int allow_count = sizeof(firewall)/sizeof(struct rule);
    char source[15];
    char dest[15];
    int port;
    int allowed = 0;
    printf("Enter source IP address: ");
    scanf("%s", source);
    printf("Enter destination IP address: ");
    scanf("%s", dest);
    printf("Enter port number: ");
    scanf("%d", &port);
    for (int i = 0; i < allow_count; i++) {
        if ((strcmp(firewall[i].source, source) == 0) &&
            (strcmp(firewall[i].dest, dest) == 0) &&
            (firewall[i].port == port)) {
            allowed = 1;
            break;
        }
    }
    if (allowed) {
        printf("Packet allowed by firewall.\n");
    } else {
        printf("Packet blocked by firewall.\n");
    }
    return 0;
}