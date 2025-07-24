//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

/* Let's define our callback function */
void pcap_callback(u_char *arg, const struct pcap_pkthdr *header, const u_char *packet)
{
    printf("Ha! Gotcha! I just captured a packet, and here are its details:\n");
    printf("Packet length: %d\n", header->len);
    printf("Number of bytes: %d\n", header->caplen);
    printf("Time: %s", ctime((const time_t *)&header->ts.tv_sec));
    printf("Dumping hex data:\n");

    /* Let's dump the hex data in a funny way */
    int i, j;
    for (i = 0; i < header->caplen; i++)
    {
        printf("%02x ", packet[i]);

        if ((i + 1) % 16 == 0)
        {
            printf(" ");
            for (j = i - 15; j <= i; j++)
            {
                if (packet[j] >= 32 && packet[j] <= 126) /* Let's print only printable ASCII characters */
                {
                    printf("%c", packet[j]);
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
    printf("\n\n");
}

int main()
{
    char *dev = "wlan0"; /* We will be sniffing on wlan0 interface. You can change it to your own interface. */
    char errbuf[PCAP_ERRBUF_SIZE]; /* Error buffer */

    /* Open the network device for sniffing */
    pcap_t *handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    if (handle == NULL)
    {
        printf("Oops! Failed to open device %s: %s\n", dev, errbuf);
        exit(1);
    }

    printf("Woohoo! Device %s is open and ready to capture packets!\n", dev);

    /* Let's set the filter */
    struct bpf_program filter;
    char filter_exp[] = "port 80"; /* We will capture only HTTP traffic for now */

    if (pcap_compile(handle, &filter, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1)
    {
        printf("Oops! Failed to set the filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    if (pcap_setfilter(handle, &filter) == -1)
    {
        printf("Oops! Failed to apply the filter: %s\n", pcap_geterr(handle));
        exit(1);
    }

    printf("Yay! The filter is set and we are ready to capture HTTP traffic!\n");

    /* Let's start sniffing! */
    pcap_loop(handle, -1, pcap_callback, NULL);

    /* Close the handle */
    pcap_close(handle);

    return 0;
}