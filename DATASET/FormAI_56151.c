//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: modular
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr *pkthdr, const u_char *packet){
    printf("Received Packet Size: %d\n", pkthdr->len);
}

int main(){

    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int timeoutLimit = 10000; /* In milliseconds */

    handle = pcap_open_live("wlan0", BUFSIZ, 1, timeoutLimit, errorBuffer);
    if(handle == NULL){
        printf("Could not open device wlan0: %s\n", errorBuffer);
        return 1;
    }

    if(pcap_datalink(handle) != DLT_EN10MB){
        /* Not Ethernet */
        printf("Device wlan0 doesn't provide Ethernet headers - not supported\n");
        return 1;
    }

    if(pcap_loop(handle, 0, packetHandler, NULL) < 0){
        printf("Error: pcap_loop returned %s\n", pcap_geterr(handle));
        return 1;
    }

    pcap_close(handle);
    return 0;
}