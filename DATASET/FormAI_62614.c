//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFSIZE 65536

int main(int argc, char *argv[]) {

    int sock_raw, i, tmp, data_size;
    struct sockaddr_in server, client;
    struct hostent *host;
    unsigned char *buffer = (unsigned char *)malloc(BUFFSIZE);
    memset(buffer, 0, BUFFSIZE);

    sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if(sock_raw < 0) {
        perror("Socket Error");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(0);

    if(bind(sock_raw, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind Error");
        return 1;
    }

    data_size = 0;
    while(1) {
        int len = sizeof(client);
        tmp = recvfrom(sock_raw, buffer, BUFFSIZE, 0, (struct sockaddr *)&client, &len);
        if(tmp < 0) {
            perror("Recvfrom Error");
            return 1;
        }

        struct iphdr *iph = (struct iphdr*)buffer;
        if(iph->protocol == IPPROTO_TCP) {
            struct tcphdr *tcph = (struct tcphdr*)(buffer + sizeof(struct iphdr));

            printf("\n\n\nTCP Packet received from %s : %d, to %s : %d\n", inet_ntoa(client.sin_addr), ntohs(tcph->source), inet_ntoa(server.sin_addr), ntohs(tcph->dest));

            printf("Header Length: %d\n", tcph->doff * 4);
            printf("Sequence Number: %u\n", tcph->seq);
            printf("Acknowledge Number: %u\n", tcph->ack_seq);
            printf("Window size: %d\n", ntohs(tcph->window));
            printf("Checksum: %d\n", ntohs(tcph->check));

            data_size = tmp - sizeof(struct iphdr) - tcph->doff * 4;
            printf("\nData:");
            for(i = 0; i < data_size; i++) {
                printf(" %02X", buffer[i + sizeof(struct iphdr) + tcph->doff * 4]);
            }
            printf("\n\n");
        }
    }

    close(sock_raw);
    free(buffer);

    return 0;
}