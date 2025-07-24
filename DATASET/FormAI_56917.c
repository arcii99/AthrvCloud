//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void custom_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main() {
  pcap_t *handle;                      // Network interface handle
  char error_buffer[PCAP_ERRBUF_SIZE]; // Error string if needed
  struct bpf_program filter;           // Compiled filter expression
  char filter_exp[] = "port 80";       // Filter expression
  bpf_u_int32 mask;                    // Subnet mask
  bpf_u_int32 net;                     // IP address of the network
  struct pcap_pkthdr header;           // Packet header
  const u_char *packet;                // Received packet
  
  // Open network interface in promiscuous mode
  handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, error_buffer);
  if (handle == NULL) {
    fprintf(stderr, "Could not open network interface: %s\n", error_buffer);
    exit(EXIT_FAILURE);
  }

  // Get network address and mask
  if (pcap_lookupnet("eth0", &net, &mask, error_buffer) == -1) {
    fprintf(stderr, "Could not get network address and mask: %s\n", error_buffer);
    exit(EXIT_FAILURE);
  }

  // Compile and apply the filter expression
  if (pcap_compile(handle, &filter, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Could not compile filter expression: %s\n", pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }
  if (pcap_setfilter(handle, &filter) == -1) {
    fprintf(stderr, "Could not apply filter expression: %s\n", pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  // Capture all incoming packets and call custom_packet_handler
  pcap_loop(handle, -1, custom_packet_handler, NULL);

  // Close network interface
  pcap_close(handle);

  return 0;
}

void custom_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
  printf("\n\n---------------\nNEW PACKET RECEIVED\n---------------\n\n");

  // Print packet information
  printf("Packet size: %d bytes\n", header->len);

  // Parse packet
  // This is where you can add your own code to analyze or manipulate the packet
}