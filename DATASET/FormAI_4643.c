//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <time.h>

#define MAX_BUFSIZE 1024
#define MAX_CONNS 10

typedef struct {
    char *ip;
    int port;
    int quality;
} Connection;

typedef struct {
    Connection conns[MAX_CONNS];
    int num_conns;
} ConnectionList;

int start_connection(char *ip, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

void close_connection(int sockfd) {
    shutdown(sockfd, SHUT_RDWR);
    close(sockfd);
}

int send_data(int sockfd, char *buf, size_t len) {
    int bytes_sent = 0;
    int bytes_left = len;
    while (bytes_sent < len) {
        int n = send(sockfd, buf + bytes_sent, bytes_left, 0);
        if (n == -1) {
            perror("send");
            return -1;
        }
        bytes_sent += n;
        bytes_left -= n;
    }
    return bytes_sent;
}

int recv_data(int sockfd, char *buf, size_t len) {
    int bytes_recv = 0;
    int bytes_left = len;
    while (bytes_recv < len) {
        int n = recv(sockfd, buf + bytes_recv, bytes_left, 0);
        if (n == -1) {
            perror("recv");
            return -1;
        }
        bytes_recv += n;
        bytes_left -= n;
    }
    return bytes_recv;
}

int ping(char *ip) {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);

    // Create ICMP packet
    char packet[64];
    memset(packet, 0, sizeof(packet));
    packet[0] = 8;  // Type: Echo Request
    packet[1] = 0;  // Code: 0
    *(unsigned short *)(packet + 2) = htons(0);  // Checksum
    *(unsigned short *)(packet + 4) = htons(0);  // Identifier
    *(unsigned short *)(packet + 6) = htons(0);  // Sequence number
    *(unsigned int *)(packet + 8) = htonl(time(NULL) & 0xFFFFFFFF);  // Timestamp
    *(unsigned int *)(packet + 12) = htonl(0xdeadbeef);  // Data

    // Calculate ICMP checksum
    unsigned int sum = 0;
    for (int i = 0; i < 16; i += 2) {
        sum += *(unsigned short *)(packet + i);
        if (sum & 0xFFFF0000) {
            sum = (sum & 0xFFFF) + 1;
        }
    }
    sum = ~sum & 0xFFFF;
    *(unsigned short *)(packet + 2) = htons(sum);

    // Send ICMP packet
    if (sendto(sockfd, packet, 64, 0, (struct sockaddr *)&addr, sizeof(addr)) != 64) {
        perror("sendto");
        close(sockfd);
        return -1;
    }

    // Wait for ICMP reply
    char buf[MAX_BUFSIZE];
    struct timeval timeout = {1, 0};
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    if (select(sockfd+1, &readfds, NULL, NULL, &timeout) == -1) {
        perror("select");
        close(sockfd);
        return -1;
    }
    if (!FD_ISSET(sockfd, &readfds)) {
        close(sockfd);
        return -1;
    }
    int bytes_recv = recv(sockfd, buf, MAX_BUFSIZE, 0);
    if (bytes_recv < 20) {
        close(sockfd);
        return -1;
    }

    // Parse ICMP reply
    unsigned short *icmp_hdr = (unsigned short *)buf;
    if (icmp_hdr[0] != 0x00) {  // Type: Echo Reply
        close(sockfd);
        return -1;
    }

    close(sockfd);
    return 0;
}

void *monitor_thread(void *arg) {
    ConnectionList *connections = (ConnectionList *)arg;

    while (1) {
        for (int i = 0; i < connections->num_conns; i++) {
            Connection *conn = &connections->conns[i];

            // Check connection quality
            int quality = ping(conn->ip);
            if (quality == 0) {
                conn->quality += 10;
            } else {
                conn->quality -= 10;
                if (conn->quality < 0) conn->quality = 0;
            }

            // Print connection status
            printf("%s:%d - Quality: %d\n", conn->ip, conn->port, conn->quality);
        }

        sleep(5);
    }
}

int main(int argc, char **argv) {
    pthread_t monitor_tid;
    ConnectionList connections;
    connections.num_conns = 0;

    // Add connections
    connections.conns[0].ip = "8.8.8.8";
    connections.conns[0].port = 53;
    connections.conns[0].quality = 100;
    connections.num_conns++;

    connections.conns[1].ip = "www.google.com";
    connections.conns[1].port = 80;
    connections.conns[1].quality = 100;
    connections.num_conns++;

    // Start monitor thread
    if (pthread_create(&monitor_tid, NULL, monitor_thread, &connections) != 0) {
        perror("pthread_create");
        return -1;
    }

    // Wait for monitor thread to exit
    if (pthread_join(monitor_tid, NULL) != 0) {
        perror("pthread_join");
        return -1;
    }

    return 0;
}