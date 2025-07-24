//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOSTS 50
#define MAX_TOPO 5000
#define MAX_NAME 20

// Structure to hold information about each host
struct Host {
    char name[MAX_NAME];
    char ip[INET_ADDRSTRLEN];
    int ports[3];
    int num_ports;
};

struct Topology {
    char from[MAX_NAME];
    char to[MAX_NAME];
};

// Function to print error messages
void print_error(char *msg) {
    fprintf(stderr, "[ERROR]: %s - %s\n", msg, strerror(errno));
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "[USAGE]: %s <network subnet>\n", argv[0]);
        exit(1);
    }

    struct Host hosts[MAX_HOSTS];
    int num_hosts = 0;

    struct Topology topology[MAX_TOPO];
    int num_edges = 0;

    char *subnet = argv[1];

    // Loop through all possible IP addresses in the subnet
    for (int i = 1; i <= 254; i++) {
        char ip[INET_ADDRSTRLEN];
        sprintf(ip, "%s.%d", subnet, i);

        // Get host name from IP address
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip);
        char hostname[MAX_NAME];
        if (getnameinfo((struct sockaddr *)&addr, sizeof(addr), hostname, MAX_NAME, NULL, 0, 0) != 0) {
            continue;
        }

        // Check if host is already in list
        int index = -1;
        for (int j = 0; j < num_hosts; j++) {
            if (strcmp(hosts[j].name, hostname) == 0) {
                index = j;
                break;
            }
        }

        if (index == -1) {
            // Add new host to list
            if (num_hosts == MAX_HOSTS) {
                fprintf(stderr, "[ERROR]: Maximum number of hosts reached\n");
                exit(1);
            }

            strcpy(hosts[num_hosts].name, hostname);
            strcpy(hosts[num_hosts].ip, ip);
            hosts[num_hosts].num_ports = 0;
            index = num_hosts;
            num_hosts++;
        }

        // Check for open ports
        int sockfd;
        struct sockaddr_in servaddr;
        
        // Check if port 22 (SSH) is open
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            continue;
        }

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr(hosts[index].ip);
        servaddr.sin_port = htons(22);

        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
            if (hosts[index].num_ports == 3) {
                fprintf(stderr, "[WARNING]: Maximum number of open ports reached for %s\n", hosts[index].name);
            } else {
                hosts[index].ports[hosts[index].num_ports] = 22;
                hosts[index].num_ports++;
            }
        }

        close(sockfd);

        // Check if port 80 (HTTP) is open
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            continue;
        }

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr(hosts[index].ip);
        servaddr.sin_port = htons(80);

        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
            if (hosts[index].num_ports == 3) {
                fprintf(stderr, "[WARNING]: Maximum number of open ports reached for %s\n", hosts[index].name);
            } else {
                hosts[index].ports[hosts[index].num_ports] = 80;
                hosts[index].num_ports++;
            }
        }

        close(sockfd);
    }

    // Output network topology
    printf("\nTopology:\n");
    for (int i = 0; i < num_hosts; i++) {
        for (int j = 0; j < num_hosts; j++) {
            if (i == j) {
                continue;
            }

            // Check if there is a connection between the two hosts
            for (int k = 0; k < hosts[i].num_ports; k++) {
                int sockfd = socket(AF_INET, SOCK_STREAM, 0);
                if (sockfd < 0) {
                    continue;
                }

                struct sockaddr_in servaddr;
                bzero(&servaddr, sizeof(servaddr));
                servaddr.sin_family = AF_INET;
                servaddr.sin_addr.s_addr = inet_addr(hosts[j].ip);
                servaddr.sin_port = htons(hosts[i].ports[k]);

                if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0) {
                    // Connection exists
                    printf("%s (%s) connected to %s (%s) on port %d\n", hosts[i].name, hosts[i].ip, hosts[j].name, hosts[j].ip, hosts[i].ports[k]);

                    // Add edge to topology
                    if (num_edges == MAX_TOPO) {
                        fprintf(stderr, "[ERROR]: Maximum number of edges reached\n");
                        exit(1);
                    }

                    strcpy(topology[num_edges].from, hosts[i].name);
                    strcpy(topology[num_edges].to, hosts[j].name);
                    num_edges++;

                    close(sockfd);
                    break;
                }

                close(sockfd);
            }
        }
    }

    return 0;
}