//FormAI DATASET v1.0 Category: Firewall ; Style: asynchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/if_packet.h>

#define MAX_PACKET_LEN 65535

void log_packet(unsigned char *pkt, int pkt_len) {
    printf("Received packet of length %d:\n", pkt_len);
    for(int i = 0; i < pkt_len; i++) {
        printf("%02x ", pkt[i]);
        if((i + 1) % 16 == 0) printf("\n");
    }
    printf("\n");
}

int main() {
    // Declare socket variables
    int sock, recv_len;
    struct sockaddr_in src_addr, dst_addr;
    socklen_t addr_len;

    // Create raw packet socket
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sock < 0) {
        perror("Socket creation error\n");
        exit(1);
    }

    while(1) {
        // Allocate receive buffer
        unsigned char recv_buffer[MAX_PACKET_LEN] = {0};
        addr_len = sizeof(src_addr);

        // Receive packet
        recv_len = recvfrom(sock, recv_buffer, MAX_PACKET_LEN, 0,
            (struct sockaddr *)&src_addr, &addr_len);
        if(recv_len < 0) {
            perror("Packet receive error\n");
            close(sock);
            exit(1);
        }

        // Parse packet headers
        struct iphdr *ip = (struct iphdr *)recv_buffer;
        int ip_hdr_len = ip->ihl * 4;
        struct tcphdr *tcp = (struct tcphdr *)(recv_buffer + ip_hdr_len);
        int tcp_hdr_len = tcp->doff * 4;
        unsigned char *payload = recv_buffer + ip_hdr_len + tcp_hdr_len;
        int payload_len = recv_len - ip_hdr_len - tcp_hdr_len;

        // Log packet
        log_packet(recv_buffer, recv_len);

        // Drop packet if source port is 1337 and destination port is 80
        if(ntohs(tcp->source) == 1337 && ntohs(tcp->dest) == 80) {
            printf("Dropped packet\n");
            continue;
        }

        // Send packet back to source address
        dst_addr.sin_family = AF_INET;
        dst_addr.sin_port = src_addr.sin_port;
        dst_addr.sin_addr.s_addr = src_addr.sin_addr.s_addr;

        if(sendto(sock, recv_buffer, recv_len, 0,
            (struct sockaddr *)&dst_addr, sizeof(dst_addr)) < 0) {
            perror("Packet send error\n");
            close(sock);
            exit(1);
        }
    }

    close(sock);
    return 0;
}