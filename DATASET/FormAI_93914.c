//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80
#define MAX_PACKET_SIZE 65535

// Struct to hold packet information
struct packet {
    struct sockaddr_in addr;
    int sock;
    char *packet_buf;
    int packet_len;
};

// Function to create raw socket and bind to address
int bind_raw_socket(int protocol) {
    int sock;
    if ((sock = socket(AF_INET, SOCK_RAW, protocol)) == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(PORT);

    if (bind(sock,(struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Failed to bind socket");
        exit(1);
    }

    return sock;
}

// Function to parse packet
void process_packet(struct packet *p) {
    // Extract the wireless network information
    char ssid[32];
    memset(ssid, 0, sizeof(ssid));
    memcpy(ssid, p->packet_buf + 26, *(p->packet_buf + 25));

    char bssid[18];
    memset(bssid, 0, sizeof(bssid));
    sprintf(bssid, "%02x:%02x:%02x:%02x:%02x:%02x",
        *(p->packet_buf + 36), *(p->packet_buf + 37),
        *(p->packet_buf + 38), *(p->packet_buf + 39),
        *(p->packet_buf + 40), *(p->packet_buf + 41));

    // Print the wireless network information
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(p->addr.sin_addr), ip, INET_ADDRSTRLEN);
    printf("SSID: %s, BSSID: %s, IP Address: %s\n", ssid, bssid, ip);
}

// Function to receive packets
void receive_packets(int sock) {
    struct sockaddr_in addr;
    int len, n;
    char packet_buf[MAX_PACKET_SIZE];

    struct packet p;
    p.sock = sock;
    p.packet_buf = packet_buf;

    while (1) {
        len = sizeof(addr);
        memset(&addr, 0, len);
        memset(packet_buf, 0, MAX_PACKET_SIZE);
        n = recvfrom(sock, packet_buf, MAX_PACKET_SIZE, 0, (struct sockaddr *)&addr, (socklen_t *)&len);

        if (n == -1) {
            perror("Failed to receive packet");
            continue;
        }

        p.addr = addr;
        p.packet_len = n;

        if (fork() == 0) {
            // In child process, process packet and exit
            process_packet(&p);
            exit(0);
        } else {
            // In parent process, continue receiving packets
            wait(NULL);
        }
    }
}

int main() {
    printf("Wireless Network Scanner started...\n");

    // Create and bind raw socket to IP protocol 3 (IP protocol for ICMP)
    int sock = bind_raw_socket(3);

    // Receive packets
    receive_packets(sock);

    return 0;
}