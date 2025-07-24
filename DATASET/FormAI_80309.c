//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: multiplayer
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/ether.h>

// Structure for keeping track of the players in the multiplayer game
struct player {
    char* name;
    char* ip_address;
};

// Array for keeping track of all the players in the game
struct player players[10];

// Counter for the number of players currently in the game
int num_players = 0;

// Function to add a new player to the game
void add_player(char* name, char* ip_address) {
    players[num_players].name = name;
    players[num_players].ip_address = ip_address;
    num_players++;
}

// Callback function for processing packets
void process_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ether_header *eth_header;
    struct ip *ip_header;
    const u_char *payload;
    int payload_size;

    eth_header = (struct ether_header *) packet;

    if (ntohs(eth_header->ether_type) != ETHERTYPE_IP)
        return;

    ip_header = (struct ip *) (packet + sizeof(struct ether_header));

    payload = packet + sizeof(struct ether_header) + sizeof(struct ip);
    payload_size = ntohs(ip_header->ip_len) - sizeof(struct ip);

    // Check if the packet is from one of the players in the game
    for (int i = 0; i < num_players; i++) {
        if (strcmp(inet_ntoa(ip_header->ip_src), players[i].ip_address) == 0) {
            printf("%s: %.*s\n", players[i].name, payload_size, payload);
        }
    }
}

int main(int argc, char **argv) {
    char errbuf[PCAP_ERRBUF_SIZE];
    char *devname;
    pcap_t *handle;
    struct bpf_program fp;
    bpf_u_int32 net, mask;

    // Get the default network interface
    devname = pcap_lookupdev(errbuf);
    if (devname == NULL) {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        exit(1);
    }
    printf("Using device %s\n", devname);

    // Get the network address and mask for the default interface
    if (pcap_lookupnet(devname, &net, &mask, errbuf) == -1) {
        fprintf(stderr, "Couldn't get network info for device: %s\n", errbuf);
        net = mask = 0;
    }

    // Open the network interface for capturing packets
    handle = pcap_open_live(devname, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", devname, errbuf);
        exit(1);
    }

    // Compile the filter expression to only capture packets from the players in the game
    char filter_expression[100];
    strcpy(filter_expression, "src host ");
    for (int i = 0; i < num_players; i++) {
        strcat(filter_expression, players[i].ip_address);
        if (i < num_players - 1) {
            strcat(filter_expression, " or src host ");
        }
    }
    printf("Filter expression: %s\n", filter_expression);
    if (pcap_compile(handle, &fp, filter_expression, 0, net) == -1) {
        fprintf(stderr, "Couldn't parse filter expression %s: %s\n", filter_expression, pcap_geterr(handle));
        exit(1);
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_expression, pcap_geterr(handle));
        pcap_freecode(&fp);
        exit(1);
    }
    pcap_freecode(&fp);

    // Start capturing packets and calling the callback function for each one
    printf("Starting packet capture...\n");
    pcap_loop(handle, -1, process_packet, NULL);

    // Cleanup
    pcap_close(handle);
    return 0;
}