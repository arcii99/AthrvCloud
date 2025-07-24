//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: unmistakable
#include <stdio.h>
#include <pcap.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data);

int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const unsigned char *packet;
    struct pcap_pkthdr packet_header;
    struct bpf_program filter;
    char expression[] = "tcp port 80";
    bpf_u_int32 subnet_mask, ip;
    int timeout_limit = 10000;
    int packets_captured = 0;

    if (pcap_lookupnet("eth0", &ip, &subnet_mask, error_buffer) == -1)
    {
        printf("Error: %s\n", error_buffer);
        return 1;
    }

    handle = pcap_create("eth0", error_buffer);

    if (handle == NULL)
    {
        printf("Error: pcap_create failed\n");
        return 1;
    }

    if (pcap_set_snaplen(handle, 1024) != 0)
    {
        printf("Error: pcap_set_snaplen failed\n");
        return 1;
    }

    if (pcap_set_promisc(handle, 1) != 0)
    {
        printf("Error: pcap_set_promisc failed\n");
        return 1;
    }

    if (pcap_set_timeout(handle, timeout_limit) != 0)
    {
        printf("Error: pcap_set_timeout failed\n");
        return 1;
    }

    if (pcap_activate(handle) != 0)
    {
        printf("Error: pcap_activate failed\n");
        return 1;
    }

    if (pcap_compile(handle, &filter, expression, 0, subnet_mask) == -1)
    {
        printf("Error: pcap_compile failed\n");
        return 1;
    }

    if (pcap_setfilter(handle, &filter) == -1)
    {
        printf("Error: pcap_setfilter failed\n");
        return 1;
    }

    pcap_loop(handle, -1, packet_handler, (unsigned char *)&packets_captured);

    pcap_close(handle);

    return 0;
}

void packet_handler(u_char *param, const struct pcap_pkthdr *packet_header, const u_char *packet_body)
{
    int *packets_captured = (int *)param;

    printf("Packet number #%d:\n", ++(*packets_captured));
    printf("Packet size:\t%d bytes\n", packet_header->len);

    struct tm ltime;
    char timestr[16];
    time_t local_tv_sec;

    local_tv_sec = packet_header->ts.tv_sec;
    localtime_r(&local_tv_sec, &ltime);
    strftime(timestr, sizeof timestr, "%H:%M:%S", &ltime);
    printf("Timestamp:\t%s\n", timestr);

    printf("Source:\t\t%s\n", inet_ntoa(*(struct in_addr *)&packet_body[26]));
    printf("Destination:\t%s\n", inet_ntoa(*(struct in_addr *)&packet_body[30]));
    printf("\n");
}