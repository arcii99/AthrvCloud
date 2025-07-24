//FormAI DATASET v1.0 Category: Network Ping Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <math.h>
#include <time.h>

#define PACKET_SIZE 64
#define ICMP_HEADER_SIZE 8
#define REPLY_BUFFER_SIZE 1024
#define MAX_ATTEMPTS 3
#define MAX_TIMEOUT 1000

void generate_ping_packet(char *packet, int sequence_no)
{
    struct icmp *icmp_header = (struct icmp*) packet;

    icmp_header->icmp_type = ICMP_ECHO;
    icmp_header->icmp_code = 0;
    icmp_header->icmp_id = (uint16_t) getpid();
    icmp_header->icmp_seq = sequence_no;
    icmp_header->icmp_cksum = 0;
    memset(packet + ICMP_HEADER_SIZE, rand() % 100, PACKET_SIZE - ICMP_HEADER_SIZE);
    struct timeval *time_sent = (struct timeval*) (packet + ICMP_HEADER_SIZE);
    gettimeofday(time_sent, NULL);
    icmp_header->icmp_cksum = 0;
    unsigned short *checksum_arr = (unsigned short*) icmp_header;

    int checksum_len = PACKET_SIZE / 2;
    unsigned long checksum = 0;
    while (checksum_len--)
    {
        checksum += *checksum_arr++;
    }

    icmp_header->icmp_cksum = ~(checksum + (checksum >> 16));
}

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return -1;
    }

    int socket_file_descriptor;
    if ((socket_file_descriptor = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
    {
        perror("socket creation failed");
        return -1;
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(argv[1]);

    char ping_packet[PACKET_SIZE];
    char reply_buffer[REPLY_BUFFER_SIZE];

    int i;
    for (i = 1; i <= MAX_ATTEMPTS; i++)
    {

        generate_ping_packet(ping_packet, i);
        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);
        sendto(socket_file_descriptor, ping_packet, PACKET_SIZE, 0, (struct sockaddr*) &address, sizeof(address));

        struct sockaddr_in reply_address;
        int reply_address_len = sizeof(reply_address);

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(socket_file_descriptor, &read_fds);

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = MAX_TIMEOUT * 1000;
        int select_result = select(socket_file_descriptor+1, &read_fds, NULL, NULL, &timeout);

        if (select_result == -1)
        {
            perror("select failed");
            return -1;
        }
        else if (select_result == 0)
        {
            printf("Request Timed out.\n");
        }
        else
        {
            int bytes_received = recvfrom(socket_file_descriptor, reply_buffer, REPLY_BUFFER_SIZE, 0, (struct sockaddr*) &reply_address, &reply_address_len);
            gettimeofday(&end_time, NULL);
            double response_time = (double) ((end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000);

            struct ip *ip_header = ( struct ip*) reply_buffer;
            int ip_header_size = ip_header->ip_hl << 2;
            struct icmp *icmp_header = (struct icmp*) (reply_buffer + ip_header_size);

            if (icmp_header->icmp_type == ICMP_ECHOREPLY)
            {
                printf("Reply received from %s (seq #%d, ttl=%d, time=%.2lf ms)\n", inet_ntoa(reply_address.sin_addr), icmp_header->icmp_seq, ip_header->ip_ttl, response_time);
            }
            else
            {
                printf("Response received from %s (unexpected response type %d)\n", inet_ntoa(reply_address.sin_addr), icmp_header->icmp_type);
            }
        }

        // Wait before sending next packet
        double delay = pow(2, i-1);
        struct timespec time_sleep;
        time_sleep.tv_sec = (int) delay / 1000;
        time_sleep.tv_nsec = (delay - time_sleep.tv_sec * 1000) * 1000 * 1000;
        nanosleep(&time_sleep, NULL);
    }

    close(socket_file_descriptor);
    return 0;
}