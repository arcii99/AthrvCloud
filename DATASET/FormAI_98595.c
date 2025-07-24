//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: statistical
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char *param, const struct pcap_pkthdr *header, const u_char *pkt_data)
{
    //Packet counter
    static int count = 1;

    //Print packet number
    printf("Packet number %d:\n", count);

    //Print packet length
    printf("Packet size: %d bytes\n", header->len);

    //Print captured time
    printf("Captured time: %s\n\n", ctime((const time_t *)&header->ts.tv_sec));

    //Increment packet counter
    count++;
}

int main(int argc, char **argv)
{
    pcap_t *descr;
    char errbuf[PCAP_ERRBUF_SIZE];

    //Open the capture file
    descr = pcap_open_offline(argv[1], errbuf);

    //Error handling for opening the capture file
    if (descr == NULL)
    {
        printf("pcap_open_offline() failed: %s\n", errbuf);
        return 1;
    }

    printf("Packet Capturer with pcap library\n");

    //Start packet capture loop
    if (pcap_loop(descr, 0, packet_handler, NULL) < 0)
    {
        printf("pcap_loop() failed: %s\n", pcap_geterr(descr));
        return 1;
    }

    //Close the capture file
    pcap_close(descr);
    return 0;
}