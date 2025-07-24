//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char const *argv[]) {
  char *interface;
  char errbuf[PCAP_ERRBUF_SIZE];
  
  if (argc > 1) {
    interface = argv[1];
  } else {
    interface = pcap_lookupdev(errbuf);
    if (interface == NULL) {
      printf("Error finding default interface: %s\n", errbuf);
      exit(1);
    }
  }
  
  printf("Using interface: %s\n", interface);
  
  pcap_t *pcap_handle;
  pcap_handle = pcap_open_live(interface, BUFSIZ, 1, 1000, errbuf);
  
  if (pcap_handle == NULL) {
    printf("Error opening interface %s: %s\n", interface, errbuf);
    exit(1);
  }
  
  printf("Ready to capture packets...\n");
  struct pcap_pkthdr header;
  const u_char *packet;
  while (1) {
    packet = pcap_next(pcap_handle, &header);
    printf("Packet captured!\n");
  }
  
  return 0;
}