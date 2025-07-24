//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shocked
#include <stdio.h>
#include <pcap.h>

void processPacket(u_char *arg, const struct pcap_pkthdr* pkthdr, const u_char *packet)
{
    printf("Packet Captured!\n");
    FILE *fp;
    fp = fopen("captured_packets.txt", "a");
    fprintf(fp, "Packet Captured!\n");
    for(int i=0; i<pkthdr->len; i++)
    {
        fprintf(fp, "%02X ", packet[i]);
        if((i+1)%16==0)
            fprintf(fp, "\n");
    }
    fprintf(fp, "\n\n");
    fclose(fp);
}

int main()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    handle = pcap_open_live("eth0", 65535, 1, 1000, errbuf);
    if (handle == NULL)
    {
        printf("Failed to open NIC card: %s\n", errbuf);
        return 1;
    }

    printf("Packet processing started...\n");
    FILE *fp;
    fp = fopen("captured_packets.txt", "w");
    fclose(fp);

    pcap_loop(handle, -1, processPacket, NULL);
    pcap_close(handle);
    printf("Packet processing completed.\n");

    return 0;
}