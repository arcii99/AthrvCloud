//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_RECV_BUF_SIZE 1024
#define MAX_HOSTS 100

void usage(char *prog_name) {
    printf("Usage: %s <start_ip> <end_ip>\n", prog_name);
}

int is_valid_ip(char *ip_str) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip_str, &(sa.sin_addr)) != 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
        return 1;
    }

    char *start_ip_str = argv[1];
    char *end_ip_str = argv[2];

    if (!is_valid_ip(start_ip_str) || !is_valid_ip(end_ip_str)) {
        printf("Invalid IP address\n");
        return 1;
    }

    struct in_addr start_ip, end_ip;
    inet_aton(start_ip_str, &start_ip);
    inet_aton(end_ip_str, &end_ip);

    if (ntohl(start_ip.s_addr) > ntohl(end_ip.s_addr)) {
        printf("Start IP should be less than end IP\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        return 1;
    }

    struct timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    char hostname[MAX_RECV_BUF_SIZE];
    char ip_str[INET_ADDRSTRLEN];

    int count = 0;
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = start_ip.s_addr;

    while (ntohl(client_addr.sin_addr.s_addr) <= ntohl(end_ip.s_addr)) {

        inet_ntop(AF_INET, &(client_addr.sin_addr), ip_str, INET_ADDRSTRLEN);
        if (getnameinfo((struct sockaddr *)&client_addr, sizeof(client_addr), hostname, MAX_RECV_BUF_SIZE, NULL, 0, NI_NAMEREQD) == 0) {
            printf("%s (%s)\n", ip_str, hostname);
        } else {
            printf("%s\n", ip_str);
        }

        client_addr.sin_addr.s_addr = htonl(ntohl(client_addr.sin_addr.s_addr) + 1);

        if(++count == MAX_HOSTS) {
            break;
        }
    }
    
    close(sockfd);
    return 0;
}