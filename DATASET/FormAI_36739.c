//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: light-weight
#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    printf("Packet captured at: %s\n", ctime((const time_t*)&pkthdr->ts.tv_sec));
    printf("Packet size: %d bytes\n", pkthdr->len);
}

int main(int argc, char** argv)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t* handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

    if(handle == NULL)
    {
        printf("Error: %s\n", errbuf);
        return 1;
    }

    printf("Packet capturing has been started...\n");

    pcap_loop(handle, -1, packet_handler, NULL);

    pcap_close(handle);
    return 0;
}