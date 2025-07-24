//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <unistd.h>

// Function to handle the captured packets
void packet_handler(u_char* user_args, const struct pcap_pkthdr* cap_header,
                    const u_char* packet){

    // Print a funny joke everytime a packet is captured
    printf("Captured a packet! Why did the computer go to the doctor?\n");
    sleep(2);
    printf("Because it had a virus!\n");
    sleep(1);

    // Retrieve the length of the packet
    int length = cap_header->len;

    // Display some information about the packet
    printf("Packet Length: %d\n", length);
    printf("Packet Data (in hex):\n");

    // Loop through the packet and print the data in hex
    for(int i=0; i<length; i++){
        printf("%02x ", packet[i]);
    }

    printf("\n\n");
}

int main(){

    // Define some variables to be used later
    char* dev;
    bpf_u_int32 mask;
    bpf_u_int32 net;
    char errbuf[PCAP_ERRBUF_SIZE];
    struct bpf_program filter;
    char filter_exp[] = "icmp"; // Filter only ICMP packets

    // Retrieve the name of the network interface to be used
    dev = pcap_lookupdev(errbuf);

    // Check if an error occurred while retrieving the interface name
    if(dev == NULL){
        printf("Error finding device: %s\n", errbuf);
        return EXIT_FAILURE;
    }

    // Print the name of the interface
    printf("Listening on device: %s\n\n", dev);

    // Retrieve the network and subnet mask properties of the interface
    if(pcap_lookupnet(dev, &net, &mask, errbuf) == -1){
        printf("Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }

    // Open the interface for packet capturing
    pcap_t* handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);

    // Check if an error occurred while opening the interface
    if(handle == NULL){
        printf("Couldn't open device %s: %s\n", dev, errbuf);
        return EXIT_FAILURE;
    }

    // Compile the filter expression
    if(pcap_compile(handle, &filter, filter_exp, 0, net) == -1){
        printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Apply the filter to the captured packets
    if(pcap_setfilter(handle, &filter) == -1){
        printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        pcap_close(handle);
        return EXIT_FAILURE;
    }

    // Start capturing packets indefinitely
    pcap_loop(handle, -1, packet_handler, NULL);

    // Close the interface once we're done capturing packets
    pcap_close(handle);

    return EXIT_SUCCESS;
}