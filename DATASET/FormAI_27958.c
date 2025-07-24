//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: excited
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>

/* Callback function to print captured data */
void packet_handler(u_char* param, const struct pcap_pkthdr* header, const u_char* data)
{
    printf("Packet Length: %d\n", header->len); 
    printf("Captured Data: ");

    for (int i = 0; i < header->caplen; i++) {
        printf("%02x ", *(data+i));
    }

    printf("\n\n");
}

/* Main function to capture packets */
int main()
{
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t* handle;

    /* Get a handle for the network device */
    handle = pcap_open_live("eth0", 65536, 1, 0, error_buffer);

    if (handle == NULL) {
        printf("Error opening device: %s\n", error_buffer);
        return 1;
    }

    /* Start capturing packets */
    printf("Capturing packets....\n");

    pcap_loop(handle, -1, packet_handler, NULL);

    /* Close the handle */
    pcap_close(handle);

    return 0;
}