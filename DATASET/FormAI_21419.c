//FormAI DATASET v1.0 Category: Firewall ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>    
#include <netinet/tcp.h>   
#include <arpa/inet.h> 
#include <unistd.h>       
#include <sys/socket.h>   

#define MAX_CONNECTIONS 100  
#define PACKET_SIZE 4096     

void handle_connection(int client_sock); 
int check_packet(struct iphdr* iph, struct tcphdr* tcph); 
void print_packet(struct iphdr* iph, struct tcphdr* tcph); 

int main(int argc, char *argv[]) {
    int server_sock, client_sock, n;
    unsigned int client_len;
    struct sockaddr_in server_addr, client_addr;

    server_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_sock < 0) {
        perror("Socket creation failed!");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed!");
        exit(1);
    }

    if (listen(server_sock, MAX_CONNECTIONS) < 0) {
        perror("Listening failed!");
        exit(1);
    }

    printf("Listening for incoming connections...\n");

    while (1) {
        client_len = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*) &client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed!");
            exit(1);
        }

        printf("\nGot a connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_connection(client_sock);

        close(client_sock);
    }

    close(server_sock);
    return 0;
}

void handle_connection(int client_sock) {
    int numpackets = 0, payload_size, total_payload_size = 0;
    struct iphdr *iph;
    struct tcphdr *tcph;
    char packet[PACKET_SIZE];

    while ((numpackets++) < 10) {
        memset(packet, 0, PACKET_SIZE);
        payload_size = recv(client_sock, packet, PACKET_SIZE, 0);
        if (payload_size < 0) {
            perror("Receiving failed!");
            break;
        }

        iph = (struct iphdr*) packet;
        tcph = (struct tcphdr*) (packet + (iph->ihl * 4));
        if (check_packet(iph, tcph)) {
            printf("\nPacket #%d\n", numpackets);
            print_packet(iph, tcph);
            total_payload_size += payload_size;
        } else {
            printf("\nBlocked suspicious packet #%d\n", numpackets);
        }
    }

    printf("\nTotal payload size: %d bytes\n", total_payload_size);
}

int check_packet(struct iphdr* iph, struct tcphdr* tcph) {
    int source_port = ntohs(tcph->source);
    if (source_port == 666) { 
        return 0; 
    }

    int destination_port = ntohs(tcph->dest);
    if (destination_port != 8888) { 
        return 0; 
    }

    int tcp_flags = tcph->syn + tcph->fin + tcph->rst + tcph->ack;
    if (tcp_flags != 1) { 
        return 0; 
    }

    return 1;
}

void print_packet(struct iphdr* iph, struct tcphdr* tcph) {
    printf("Source IP: %s\n", inet_ntoa(*(struct in_addr*) &iph->saddr));
    printf("Destination IP: %s\n", inet_ntoa(*(struct in_addr*) &iph->daddr));
    printf("Source port: %d\n", ntohs(tcph->source));
    printf("Destination port: %d\n", ntohs(tcph->dest));
    printf("TCP flags: SYN=%d, FIN=%d, RST=%d, ACK=%d\n", tcph->syn, tcph->fin, tcph->rst, tcph->ack);
}