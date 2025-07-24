//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: shocked
#include<stdio.h>
#include<pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char const *argv[])
{
    pcap_t *capture;
    char error_buffer[PCAP_ERRBUF_SIZE];
    char *network_device;

    //Get the default network device
    network_device = pcap_lookupdev(error_buffer);
    if(network_device == NULL){
        printf("Error finding network device: %s\n", error_buffer);
        return 1;
    }
    printf("Using network device: %s\n", network_device);

    //Open the capture session
    capture = pcap_open_live(network_device, BUFSIZ, 1, 1000, error_buffer);
    if(capture == NULL){
        printf("Error opening capture session: %s\n", error_buffer);
        return 1;
    }

    //Start the capture loop
    pcap_loop(capture, -1, packet_handler, NULL);

    //Close the capture session
    pcap_close(capture);

    return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
    printf("Packet captured.\n");
    printf("Ethernet Header\n");
    printf("Destination MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n", packet[0], packet[1],
           packet[2], packet[3], packet[4], packet[5]);
    printf("Source MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n", packet[6], packet[7],
           packet[8], packet[9], packet[10], packet[11]);
    printf("Type: %u\n", (uint32_t)packet[12] << 8 | (uint32_t)packet[13]);
    printf("Payload: ");
    for(int i = 14; i < header->len; i++){
        printf("%02X", packet[i]);
    }
    printf("\n\n");
}