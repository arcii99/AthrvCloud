//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>
#include <netinet/ether.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet)
{
    printf("----------------\n");
    printf("Received packet\n");
    printf("----------------\n");

    struct ether_header *etherHeader = (struct ether_header *)packet;
    printf("Source MAC: %s\n", ether_ntoa((const struct ether_addr *)etherHeader->ether_shost));
    printf("Destination MAC: %s\n", ether_ntoa((const struct ether_addr *)etherHeader->ether_dhost));

    uint16_t ethertype = ntohs(etherHeader->ether_type);
    printf("Ether type: %04x\n", ethertype);

    /* Check the protocol of the packet */
    switch (ethertype)
    {
    case 0x0800:
        printf("Protocol: IPv4\n");
        break;
    case 0x0806:
        printf("Protocol: ARP\n");
        break;
    case 0x86dd:
        printf("Protocol: IPv6\n");
        break;
    default:
        printf("Unknown protocol\n");
    }

    if (ethertype == 0x0800)
    {
        /* Extract the source and destination IP address */
        const u_char *ipHeader = packet + sizeof(struct ether_header);
        struct in_addr source, dest;
        memcpy(&source, ipHeader + 12, 4);
        memcpy(&dest, ipHeader + 16, 4);

        printf("Source IP address: %s\n", inet_ntoa(source));
        printf("Destination IP address: %s\n", inet_ntoa(dest));
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    char *device;
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeoutLimit = 10000; // Timeout in milliseconds

    /* Find a device to capture packets on */
    device = pcap_lookupdev(errorBuffer);
    if (device == NULL)
    {
        printf("Error finding device: %s\n", errorBuffer);
        return 1;
    }

    /* Open the device */
    handle = pcap_open_live(device, BUFSIZ, 1, timeoutLimit, errorBuffer);
    if (handle == NULL)
    {
        printf("Error opening device: %s\n", errorBuffer);
        return 1;
    }

    /* Start the packet capture loop */
    pcap_loop(handle, -1, packetHandler, NULL);

    /* Cleanup */
    pcap_close(handle);

    printf("Packet capture complete.\n");

    return 0;
}