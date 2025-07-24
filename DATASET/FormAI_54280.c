//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: active
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

void packetHandler(u_char* userData, const struct pcap_pkthdr* pkthdr, const u_char* packet){

    // Cast the user passed argument to another pointer to a different data type
    int* counter = (int*)userData;
    printf("Packet count: %d\n", ++(*counter));
    printf("Packet length: %d\n", pkthdr->len);

}

int main(){

    char* device; // pointer to the interface name
    char errorBuffer[PCAP_ERRBUF_SIZE]; // buffer to store error message

    // Get the interface name
    device = pcap_lookupdev(errorBuffer);
    if(device == NULL){

        printf("Error finding device: %s\n", errorBuffer);
        return 1;

    }

    // Open the capture device
    pcap_t* handle;
    handle = pcap_open_live(device, BUFSIZ, 1, 1000, errorBuffer);
    if(handle == NULL){

        printf("Error opening device: %s\n", errorBuffer);
        return 1;

    }

    // Start the capture process
    int packetCount = 0;
    pcap_loop(handle, 0, packetHandler, (u_char*)&packetCount);

    // Close the capture device
    pcap_close(handle);
    printf("Capture complete.\n");

    return 0;

}