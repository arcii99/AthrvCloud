//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 65536

void processData(unsigned char*, int);
void processPacket(unsigned char*, int);

int main() {
    int sock, length;
    unsigned char buffer[BUFFER_SIZE];
    struct sockaddr_in source, dest;
    length = sizeof(struct sockaddr_in);
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        printf("Socket Error\n");
        return 1;
    }
    while (1) {
        if (recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&source, &length) < 0) {
            printf("Receive Error\n");
            return 1;
        }
        processPacket(buffer, length);
    }

    return 0;
}

void processPacket(unsigned char* buffer, int length) {
    struct iphdr* iph = (struct iphdr*)buffer;
    if (iph->protocol == IPPROTO_TCP) {
        processData(buffer + iph->ihl*4, length - iph->ihl*4);
    }
}

void processData(unsigned char* data, int length) {
    struct tcphdr* tcph = (struct tcphdr*)data;
    int header_size = tcph->doff*4;
    unsigned char* message = data + header_size;
    int message_size = length - header_size;
    printf("[CLIENT] Message Received: ");
    for (int i = 0; i < message_size; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}