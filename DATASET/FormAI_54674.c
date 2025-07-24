//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Sherlock Holmes
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *pcap_handle;
  struct bpf_program filter;
  bpf_u_int32 mask;
  bpf_u_int32 net;

  // Open the network interface for packet capture
  pcap_handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
  if (pcap_handle == NULL) {
    printf("Failed to open eth0: %s\n", errbuf);
    return 1;
  }

  // Compile the filter expression to only capture HTTP traffic
  if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
    printf("Failed to get netmask for eth0: %s\n", errbuf);
    return 1;
  }
  if (pcap_compile(pcap_handle, &filter, "tcp port 80", 0, net) == -1) {
    printf("Failed to compile filter expression: %s\n", pcap_geterr(pcap_handle));
    return 1;
  }
  if (pcap_setfilter(pcap_handle, &filter) == -1) {
    printf("Failed to set filter: %s\n", pcap_geterr(pcap_handle));
    return 1;
  }

  // Capture and print packets until interrupted
  struct pcap_pkthdr header;
  const u_char *packet;
  while (1) {
    packet = pcap_next(pcap_handle, &header);
    if (packet == NULL) {
      continue;
    }

    printf("Packet captured: length = %d\n", header.len);
    // Do something else with the captured packets
  }

  // Close the pcap handle and exit
  pcap_close(pcap_handle);
  return 0;
}