//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 65536

int main() {
    int sock_raw;
    int size;
    struct sockaddr_in server;
    unsigned char *buffer = (unsigned char *)malloc(BUFFER_SIZE);
    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock_raw < 0) {
        printf("Socket Error\n");
        return 1;
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(0);
    if (bind(sock_raw, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Binding Error\n");
        close(sock_raw);
        return 1;
    }
    while(1) {
        size = recvfrom(sock_raw, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (size < 0) {
            printf("Packet Recieve Error\n");
            close(sock_raw);
            return 1;
        }
        printf("-- PACKET START --\n");
        for(int i = 0; i < size; i++) {
            if (i % 16 == 0) {
                printf("\n");
            }
            printf("%02X ", buffer[i]);
        }
        printf("\n-- PACKET END --\n");
    }
    close(sock_raw);
    return 0;
}