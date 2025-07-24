//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: active
#include <pcap.h>
#include <stdio.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet)
{
    printf("Packet handled\n");
}

int main(int argc, char *argv[])
{
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeoutLimit = 10000; // 10 seconds
    
    // Open the capture device specified in argv[1]
    handle = pcap_open_live(argv[1], 65536, 1, timeoutLimit, errorBuffer);
    
    // Check if the device was opened correctly
    if (handle == NULL) {
        printf("Could not open device %s: %s\n", argv[1], errorBuffer);
        return 1;
    }
    
    // Start capturing packets
    if (pcap_loop(handle, -1, packetHandler, NULL) < 0) {
        printf("Error while capturing packets: %s\n", pcap_geterr(handle));
        return 1;
    }
    
    // Close the capture device
    pcap_close(handle);
    
    return 0;
}