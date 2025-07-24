//FormAI DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netinet/in.h>

#define MAX_PACKET_SIZE 65535
#define DEFAULT_TIMEOUT 2

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address or hostname>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;

    int address_result = inet_pton(AF_INET, hostname, &server_address.sin_addr);
    if (address_result == 0) {
        printf("Invalid IP address or hostname\n");
        return 1;
    } else if (address_result < 0) {
        perror("inet_pton");
        return 1;
    }

    int socket_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (socket_fd < 0) {
        perror("socket");
        return 1;
    }

    printf("PING %s (%s) 56(84) bytes of data.\n", hostname, inet_ntoa(server_address.sin_addr));

    unsigned char packet[MAX_PACKET_SIZE] = {0};
    packet[0] = 8; // ICMP Echo Request
    packet[1] = 0; // Code
    packet[2] = 0; // Checksum (to be overwritten)
    packet[3] = 0;
    packet[4] = 0x42; // Identifier
    packet[5] = 0x42;
    packet[6] = 0; // Sequence number (to be incremented later)
    packet[7] = 0;

    unsigned short checksum = 0;
    for (int i = 0; i < 8; ++i) {
        checksum += packet[i] << 8;
        checksum += packet[i + 1];
    }
    checksum = ~checksum;
    packet[2] = checksum >> 8;
    packet[3] = checksum & 0xFF;

    struct timeval timeout = {DEFAULT_TIMEOUT, 0};

    int sequence_number = 0;
    int sent_count = 0;
    int recv_count = 0;
    int lost_count = 0;
    float min_time = -1;
    float max_time = -1;
    float total_time = 0;

    while (sent_count < 10) { // Send 10 packets
        sequence_number++;
        packet[6] = sequence_number >> 8;
        packet[7] = sequence_number & 0xFF;

        struct timeval send_time;
        gettimeofday(&send_time, NULL);

        int send_result = sendto(socket_fd, packet, sizeof(packet), 0, (struct sockaddr*)&server_address, sizeof(server_address));
        if (send_result < 0) {
            perror("sendto");
            lost_count++;
            continue;
        }

        sent_count++;

        fd_set read_set;
        FD_ZERO(&read_set);
        FD_SET(socket_fd, &read_set);

        int select_result = select(socket_fd + 1, &read_set, NULL, NULL, &timeout);
        if (select_result < 0) {
            perror("select");
            lost_count++;
            continue;
        } else if (select_result == 0) {
            printf("Request timeout for icmp_seq %d\n", sequence_number);
            lost_count++;
            continue;
        }

        struct sockaddr_in recv_address;
        socklen_t recv_address_size = sizeof(recv_address);
        unsigned char recv_packet[MAX_PACKET_SIZE] = {0};

        struct timeval recv_time;
        gettimeofday(&recv_time, NULL);

        int recv_result = recvfrom(socket_fd, recv_packet, sizeof(recv_packet), 0, (struct sockaddr*)&recv_address, &recv_address_size);
        if (recv_result < 0) {
            perror("recvfrom");
            lost_count++;
            continue;
        }

        if (recv_packet[0] == 0 && recv_packet[1] == 0) { // ICMP Echo Reply
            recv_count++;

            float elapsed_time = (recv_time.tv_sec - send_time.tv_sec) * 1000.0;
            elapsed_time += (recv_time.tv_usec - send_time.tv_usec) / 1000.0;

            total_time += elapsed_time;

            if (min_time < 0 || elapsed_time < min_time) {
                min_time = elapsed_time;
            }
            if (max_time < 0 || elapsed_time > max_time) {
                max_time = elapsed_time;
            }

            printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.1f ms\n",
                   recv_result, inet_ntoa(recv_address.sin_addr), sequence_number, 
                   recv_packet[8], elapsed_time);
        } else {
            lost_count++;
            continue;
        }
    }

    printf("\n--- %s ping statistics ---\n", hostname);
    printf("%d packets transmitted, %d received, %.1f%% packet loss, time %.0fms\n", sent_count, recv_count,
           ((float)lost_count / sent_count) * 100, total_time);

    if (recv_count > 0) {
        printf("rtt min/avg/max = %.3f/%.3f/%.3f ms\n", min_time, total_time / recv_count, max_time);
    }

    close(socket_fd);

    return 0;
}