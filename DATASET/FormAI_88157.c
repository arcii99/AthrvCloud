//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

#define MAX_PORT 65535
#define MAX_ADDR_LEN 46 // Maximum length of IP address + port
#define PORT_RANGE 100  // Number of nearby ports to scan
#define MAX_RESULT_LEN 10000 // Maximum length of scan results

void scan_addr(char *addr, int min_port, int max_port, char **results) {
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof sa);
    sa.sin_family = AF_INET;
    inet_pton(AF_INET, addr, &(sa.sin_addr));

    for (int port = min_port; port <= max_port; ++port) {
        if (port >= 1) {
            int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (sock < 0) {
                perror("socket creation failed");
                exit(1);
            }

            sa.sin_port = htons(port);
            int res = connect(sock, (struct sockaddr *)&sa, sizeof(sa));
            if (res < 0) {
                continue; // port is closed or filtered
            }

            char addr_port[MAX_ADDR_LEN];
            sprintf(addr_port, "%s:%d", addr, port);
            strcat(*results, addr_port);
            strcat(*results, "\n");
            close(sock);
        }
    }
}

int main() {
    printf("*** C Wireless Network Scanner ***\n");
    printf("Enter the IP address range to scan (e.g. 192.168.0.1-10): ");
    char ip_range[20];
    fgets(ip_range, sizeof(ip_range), stdin);

    printf("Enter the range of ports to scan (e.g. 1-100): ");
    char port_range[10];
    fgets(port_range, sizeof(port_range), stdin);

    // Parse the IP range
    char *dash = strchr(ip_range, '-');
    if (dash == NULL) {
        printf("Invalid IP range\n");
        exit(1);
    }

    *dash = '\0';
    char *start_ip = ip_range;
    char *end_ip = dash + 1;

    // Parse the port range
    dash = strchr(port_range, '-');
    if (dash == NULL) {
        printf("Invalid port range\n");
        exit(1);
    }

    *dash = '\0';
    int start_port = atoi(port_range);
    int end_port = atoi(dash + 1);

    if (start_port < 1 || start_port > MAX_PORT || end_port < 1 || end_port > MAX_PORT || start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    printf("\nScanning...\n");
    char *results = (char*) malloc(MAX_RESULT_LEN);
    memset(results, 0, MAX_RESULT_LEN);

    for (int i = atoi(start_ip + 3); i <= atoi(end_ip + 3); ++i) {
        char addr[20];
        memset(addr, 0, sizeof addr);
        sprintf(addr, "%.*s.%d", (int)(dash - start_ip - 1), start_ip, i);
        scan_addr(addr, start_port, end_port, &results);
    }

    printf("\nScan result:\n%s", results);
    free(results);

    return 0;
}