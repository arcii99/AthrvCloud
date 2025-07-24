//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PACKET_SIZE 4096

int main(int argc, char *argv[]) {
    char *target_ip = argv[1];
    int target_port = atoi(argv[2]);
    int sock;
    struct sockaddr_in addr;
    char packet[MAX_PACKET_SIZE];

    sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(target_ip);
    addr.sin_port = htons(target_port);

    memset(packet, 0xFF, sizeof packet);

    while (1) {
        sendto(sock, packet, sizeof packet, 0, (struct sockaddr *) &addr, sizeof addr);
        usleep(100000); // wait for 100ms
    }
}