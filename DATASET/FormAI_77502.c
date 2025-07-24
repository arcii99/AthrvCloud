//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complete
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <errno.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    struct ether_header* ethernetHeader;
    struct ip* ipHeader;
    struct tcphdr* tcpHeader;
    u_char* payload;

    int ethernetHeaderSize = sizeof(struct ether_header);
    ethernetHeader = (struct ether_header*)packet;

    if (ntohs(ethernetHeader->ether_type) == ETHERTYPE_IP)
    {
        ipHeader = (struct ip*)(packet + ethernetHeaderSize);

        if (ipHeader->ip_p == IPPROTO_TCP)
        {
            tcpHeader = (struct tcphdr*)(packet + ethernetHeaderSize + sizeof(struct ip));

            int tcpHeaderSize = tcpHeader->doff * 4;
            int payloadSize = ntohs(ipHeader->ip_len) - (sizeof(struct ip) + tcpHeaderSize);
            payload = (u_char*)(packet + ethernetHeaderSize + sizeof(struct ip) + tcpHeaderSize);

            printf("Source IP: %s\n", inet_ntoa(ipHeader->ip_src));
            printf("Destination IP: %s\n", inet_ntoa(ipHeader->ip_dst));

            if (payloadSize > 0)
            {
                printf("Payload:\n");
                for (int i = 0; i < payloadSize; i++)
                {
                    printf("%02x ", payload[i]);
                }
                printf("\n");
            }
            else
            {
                printf("No Payload\n");
            }
        }
    }
}

int main(int argc, char* argv[])
{
    char* device;
    pcap_t* handle;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filterExpression[] = "tcp";
    bpf_u_int32 subnetMask;
    bpf_u_int32 ipAddress;

    if(argc > 1)
    {
        device = argv[1];
    }
    else
    {
        device = pcap_lookupdev(errorBuffer);
        if (device == NULL)
        {
            printf("Error finding default device: %s\n", errorBuffer);
            exit(1);
        }
    }

    printf("Sniffing on device: %s\n", device);

    if (pcap_lookupnet(device, &ipAddress, &subnetMask, errorBuffer) == -1)
    {
        printf("Error getting IP and Subnet Mask configuration for device: %s\n", errorBuffer);
        subnetMask = 0;
        ipAddress = 0;
    }

    if ((handle = pcap_open_live(device, BUFSIZ, 1, 1000, errorBuffer)) == NULL)
    {
        printf("Error opening device for sniffing: %s\n", errorBuffer);
        exit(1);
    }

    if (pcap_compile(handle, &filter, filterExpression, 0, ipAddress) == -1)
    {
        printf("Error while parsing filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &filter) == -1)
    {
        printf("Error setting filter expression: %s\n", pcap_geterr(handle));
        exit(1);
    }

    pcap_loop(handle, -1, packetHandler, NULL);

    pcap_close(handle);

    return 0;
}