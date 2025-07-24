//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 427

struct wireless_packet {
    uint8_t type;
    uint8_t subtype;
    uint16_t duration;
    uint8_t receiver[6];
    uint8_t source[6];
    uint8_t bssid[6];
    uint16_t frag_seq_ctrl;
    uint8_t ssid_len;
    uint8_t ssid[MAX_PACKET_SIZE];
};

void wireless_packet_init(struct wireless_packet *pak) {
    memset(pak, 0, sizeof(struct wireless_packet));
}

int main(int argc, char **argv) {
    struct sockaddr_in rawsock;
    struct wireless_packet packet;
    memset(&rawsock, 0, sizeof(rawsock));

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0) {
        perror("Failed to create raw socket");
        return -1;
    }

    rawsock.sin_family = AF_INET;
    rawsock.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(sockfd, (struct sockaddr *)&rawsock, sizeof(struct sockaddr_in));

    while (1) {
        printf("[*] Waiting for packets...\n");
        uint8_t buffer[MAX_PACKET_SIZE];
        memset(buffer, 0, MAX_PACKET_SIZE);

        int num_bytes = recv(sockfd, buffer, MAX_PACKET_SIZE, 0);
        if (num_bytes > 0) {
            wireless_packet_init(&packet);
            memcpy(&packet, buffer, num_bytes);

            if (packet.type == 0x80 && packet.subtype == 0x00) {
                printf("[+] Beacon frame found!\n");
                printf(" - SSID: %.*s\n", (int)packet.ssid_len, packet.ssid);
                printf(" - BSSID: %02X:%02X:%02X:%02X:%02X:%02X\n",
                        packet.bssid[0], packet.bssid[1], packet.bssid[2],
                        packet.bssid[3], packet.bssid[4], packet.bssid[5]);
            }
        }
    }

    return 0;
}