//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<pcap.h>

char *devname;

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    // This function will be called for every packet received by pcap_loop
    printf("Packet captured!\n");
}

void usage(char *program_name) {
    printf("Usage: %s [interface]\n", program_name);
    printf("If interface is not specified, the program will use the default interface.\n");
}

int main(int argc, char **argv) {
    // Get the device name from command line arguments
    if(argc > 2) {
        usage(argv[0]);
        exit(1);
    } else if(argc == 2) {
        devname = argv[1];
    } else {
        devname = pcap_lookupdev(NULL);
        if(devname == NULL) {
            perror("pcap_lookupdev");
            exit(1);
        }
    }

    printf("Using device: %s\n", devname);

    // Open the device in promiscuous mode
    pcap_t *handle = pcap_open_live(devname, BUFSIZ, 1, 1000, NULL);
    if(handle == NULL) {
        perror("pcap_open_live");
        exit(1);
    }

    // Set the filter to only capture TCP traffic
    struct bpf_program fp;
    char filter_exp[] = "tcp";
    if(pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        perror("pcap_compile");
        exit(1);
    }
    if(pcap_setfilter(handle, &fp) == -1) {
        perror("pcap_setfilter");
        exit(1);
    }

    // Start sniffing packets
    if(pcap_loop(handle, -1, packet_handler, NULL) == -1) {
        perror("pcap_loop");
        exit(1);
    }

    // Close the handle
    pcap_close(handle);

    return 0;
}