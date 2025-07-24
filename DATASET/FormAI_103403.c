//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <math.h>
#include <unistd.h>

#define BUFLEN 1000
#define PORT 8888

struct packet_statistics {
    long long int total_packets_sent;
    long long int total_packets_received;
};

struct bandwidth_statistics {
    double throughput;
    double bandwidth;
};

struct latency_statistics {
    double average_latency;
    double mean_deviation;
};

void error(char *s)
{
    perror(s);
    exit(1);
}

int main(void)
{
    struct sockaddr_in my_addr, cli_addr;
    int sockfd, i;
    socklen_t slen=sizeof(cli_addr);
    char buf[BUFLEN];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        error("socket");

    memset((char *) &my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr* ) &my_addr, sizeof(my_addr))==-1)
        error("bind");

    struct packet_statistics packet_stats = {0, 0};
    struct bandwidth_statistics bandwidth_stats = {0, 0};
    struct latency_statistics latency_stats = {0, 0};
    double summed_latency = 0;
    double squared_summed_latency = 0;
    int num_packets = 0;
    int current_seq = -1;

    while(1) {
        if ((recvfrom(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&cli_addr, &slen))==-1)
            error("recvfrom()");

        int seq = atoi(buf);
        if (current_seq == -1) {
            current_seq = seq;
        }
        int latency = abs(current_seq - seq);
        current_seq = seq;

        summed_latency += latency;
        squared_summed_latency += pow(latency, 2);
        num_packets++;
        packet_stats.total_packets_received++;

        snprintf(buf, BUFLEN, "%d", seq);

        if ((sendto(sockfd, buf, BUFLEN, 0, (struct sockaddr*)&cli_addr, slen))==-1)
            error("sendto()");

        packet_stats.total_packets_sent++;

        if (packet_stats.total_packets_received % 100 == 0) {
            double total_latency = summed_latency / num_packets;
            double average_latency = total_latency / 1000;
            latency_stats.average_latency = average_latency;

            double mean_deviation = sqrt((squared_summed_latency / num_packets) - pow(total_latency, 2));
            double mean_deviation_milliseconds = mean_deviation / 1000;
            latency_stats.mean_deviation = mean_deviation_milliseconds;

            double time_elapsed_seconds = ((double) num_packets * BUFLEN * 8) / (1000000 * bandwidth_stats.throughput);
            double bandwidth = (num_packets * BUFLEN * 8) / (time_elapsed_seconds * 1000000);
            bandwidth_stats.bandwidth = bandwidth;

            double throughput = num_packets * BUFLEN / time_elapsed_seconds;
            bandwidth_stats.throughput = throughput;

            printf("Packet Stats:\n");
            printf("  Total Packets Sent: %lld\n", packet_stats.total_packets_sent);
            printf("  Total Packets Received: %lld\n", packet_stats.total_packets_received);
            printf("\n");

            printf("Bandwidth Stats:\n");
            printf("  Throughput: %.3lf MB/s\n", bandwidth_stats.throughput / 1e6);
            printf("  Bandwidth: %.3lf Mbps\n", bandwidth_stats.bandwidth / 1e6);
            printf("\n");

            printf("Latency Stats:\n");
            printf("  Average Latency: %.3lf ms\n", latency_stats.average_latency);
            printf("  Mean Deviation: %.3lf ms\n", latency_stats.mean_deviation);
            printf("\n");
        }
    }

    close(sockfd);
    return 0;
}