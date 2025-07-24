//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: expert-level
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    printf("Packet capture length: %d\n", pkthdr->caplen);
    
    // retrieve the timestamp
    struct tm *timeinfo;
    char buffer[80];
    time_t timestamp = (time_t)pkthdr->ts.tv_sec;
    timeinfo = localtime(&timestamp);
    strftime(buffer,80,"%Y-%m-%d %I:%M:%S", timeinfo);
    printf("Timestamp: %s.%06ld\n", buffer, pkthdr->ts.tv_usec);
    
    // print the packet in hex format
    int i;
    for(i = 0; i < pkthdr->caplen; i++)
    {
        printf("%.2x ", packet[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    pcap_t *handle;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program fp;
    char filter_exp[] = "tcp port 80";
    bpf_u_int32 net;
    
    // Open the capture device
    handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening capture device: %s\n", errbuf);
        return 1;
    }
    
    // Compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
        fprintf(stderr, "Error compiling filter expression\n");
        return 1;
    }
    
    // Apply the filter expression
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Error applying filter expression\n");
        return 1;
    }
    
    // Capture packets until timeout or error occurs
    pcap_loop(handle, 0, packetHandler, NULL);
    
    // Close the capture device and free resources
    pcap_close(handle);
    return 0;
}