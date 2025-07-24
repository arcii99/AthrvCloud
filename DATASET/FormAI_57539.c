//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: retro
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packetData)
{
    int i=0;
    
    printf("\n\nPacket #%d\n", ++(*((int *)userData)));
    
    for(i=0; i<pkthdr->len; ++i)
    {
        if (i % 16 == 0) printf("\n");
        
        printf("%.2x ", packetData[i]);
    }
}

int main()
{
    char errBuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packetCount = 0;
    
    //open capture file for offline processing
    handle = pcap_open_offline("capture.pcap", errBuf);
    
    //loop through packets in file and print them to console
    pcap_loop(handle, 0, packetHandler, (u_char *)&packetCount);
    
    printf("\nPacket capture complete.\n");
    
    return 0;
}