//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <pcap.h> //includes the pcap library                      
#include <stdio.h> //includes the standard I/O libraries                   

int main() {  //main function starts here     
        
        //defines some essential variables to be used
        pcap_t *handle;
        char error_buffer[PCAP_ERRBUF_SIZE];
        struct pcap_pkthdr header;
        const u_char *packet;

        //opens a network interface for listening
        handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);

        //checks if the network interface is successfully opened or not
        if (handle == NULL) {
                printf("Could not open device eth0: %s", error_buffer);
                return 1;
        }

        //prints a success message if network interface is opened successfully
        printf("Successfully opened device eth0\n");

        //captures a packet from the network interface and stores it in *packet
        packet = pcap_next(handle, &header);

        //prints some details of the captured packet
        printf("Packet length: %d\n", header.len);
        printf("Number of bytes: %d\n", header.caplen);
        printf("Received time: %s", ctime((const time_t *)&header.ts.tv_sec));
                                                                
        //closes the network interface
        pcap_close(handle);
        return 0;
}