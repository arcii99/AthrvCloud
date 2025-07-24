//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: immersive
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packet_handler_callback(u_char *useless, const struct pcap_pkthdr *pkthdr, const u_char *packet)
{
    static int count = 0;

    printf("Packet number %d:\n", ++count);

    /* Show the size of the packet */
    printf("  Packet size: %d bytes\n", pkthdr->len);

    /* Loop through the packet looking for data */
    int i = 0;
    for(i = 0; i < pkthdr->len; i++)
    {
        /* Display each byte */
        printf(" %02x", packet[i]);
        if((i + 1) % 16 == 0)
        {
            printf("\n");
        }
    }

    printf("\n\n");
}

int main(int argc, char **argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle = NULL;

    /* Open pcap device for capturing */
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if(handle == NULL)
    {
        printf("Error opening device: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }

    /* Start capturing the packets */
    pcap_loop(handle, 0, packet_handler_callback, NULL);

    /* Close the session */
    pcap_close(handle);

    return 0;
}