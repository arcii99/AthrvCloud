//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTS 1000
#define MAX_IP_LEN 16

struct host {
    char *name;
    char *ip;
};

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <network_address>\n", argv[0]);
        exit(1);
    }

    char *network_address = argv[1];
    struct in_addr addr;
    if (inet_aton(network_address, &addr) == 0) {
        fprintf(stderr, "Invalid network address\n");
        exit(1);
    }

    printf("Scanning network %s...\n", network_address);

    struct host hosts[MAX_HOSTS];
    int num_hosts = 0;

    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "nmap -sn %s/24 -oG - | awk '/Up$/{print $2}'", network_address);

    FILE *fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to execute nmap\n");
        exit(1);
    }

    char ip[MAX_IP_LEN];
    while (fgets(ip, sizeof(ip), fp) != NULL) {
        // Remove newline character from ip
        ip[strcspn(ip, "\n")] = 0;

        struct host h;
        h.name = NULL;
        h.ip = strdup(ip);
        hosts[num_hosts++] = h;
    }

    pclose(fp);

    printf("Found %d hosts\n", num_hosts);

    printf("Hostname\tIP Address\n");
    printf("---------\t----------\n");
    for (int i = 0; i < num_hosts; i++) {
        struct host *h = &hosts[i];

        struct sockaddr_in sa;
        memset(&sa, 0, sizeof(sa));
        sa.sin_family = AF_INET;
        inet_pton(AF_INET, h->ip, &sa.sin_addr);

        char hostname[MAX_IP_LEN];
        if (getnameinfo((struct sockaddr *)&sa, sizeof(sa), hostname, sizeof(hostname), NULL, 0, 0) != 0) {
            // Failed to get hostname, use ip in its place
            strncpy(hostname, h->ip, sizeof(hostname));
        }

        h->name = strdup(hostname);

        printf("%s\t%s\n", h->name, h->ip);
    }

    return 0;
}