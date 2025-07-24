//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    static int packet_count = 0;
    printf("\nPacket Number %d:\n", ++packet_count);
    printf("Packet Size: %d bytes\n", header->len);
    /* Code for medieval style monitoring */
    printf("By the mighty sword of Excalibur! A messenger from %d.%d.%d.%d approaches!\n", packet[26], packet[27], packet[28], packet[29]);
    if((packet[23] & 0x01) == 0x01) {
        printf("By the hammer of Thor! This message is broadcasted throughout the land!\n");
    }
    switch(packet[23] & 0x0F) {
        case 0x01:
            printf("This message travels on a noble steed!\n");
            break;
        case 0x02:
            printf("This message travels on a mighty ship!\n");
            break;
        case 0x03:
            printf("This message travels on a swift bird!\n");
            break;
        case 0x04:
            printf("This message travels on a fleet-footed messenger!\n");
            break;
        default:
            printf("This message travels on an unknown vehicle!\n");
            break;
    }
}

int main(int argc, char **argv) {
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    int packet_count_limit = 10;
    int timeout_limit = 10000; /* In milliseconds */
    char *devicename;
    bpf_u_int32 net_mask; /* The netmask of our sniffing device */
    bpf_u_int32 net_ip; /* The IP of our sniffing device */
    char filter_exp[] = "ip"; /* The filter expression */
    struct bpf_program filter_program;
    int optimize = 1; /* Set to 1 to optimize the filter expression */
    int packet_sampling = 1; /* Set to 1 to enable random packet sampling */

    devicename = pcap_lookupdev(error_buffer);
    if(devicename == NULL) {
        fprintf(stderr, "Could not find default device: %s\n", error_buffer);
        return(1);
    }
    printf("Using device: %s\n", devicename);

    /* Get the netmask and IP of the device */
    if(pcap_lookupnet(devicename, &net_ip, &net_mask, error_buffer) == -1) {
        fprintf(stderr, "Could not get information for device: %s\n", devicename);
        return(1);
    }

    /* Open the device for sniffing */
    handle = pcap_open_live(devicename, BUFSIZ, 1, timeout_limit, error_buffer);
    if(handle == NULL) {
        fprintf(stderr, "Could not open device %s: %s\n", devicename, error_buffer);
        return(1);
    }

    /* Compile the filter expression */
    if(pcap_compile(handle, &filter_program, filter_exp, optimize, net_mask) == -1) {
        fprintf(stderr, "Could not parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(1);
    }

    /* Set the filter */
    if(pcap_setfilter(handle, &filter_program) == -1) {
        fprintf(stderr, "Could not set filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(1);
    }

    /* Monitor packets in a loop */
    pcap_loop(handle, packet_count_limit, handle_packet, NULL);

    /* Close the handle */
    pcap_close(handle);

    printf("\nEnd of Program.\n");
    return 0;
}