//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: excited
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;             // Session handle
  struct pcap_pkthdr *header; // The header that pcap gives us
  const u_char *packet;       // The actual packet
  int i;

  // Define the device
  char *dev = argv[1];

  // Open the session in promiscuous mode
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return(2);
  }

  // Grab a packet
  while(1) {
    packet = pcap_next(handle, &header);
    if (packet == NULL) continue;

    // Print its length
    printf("JUMPING IN 3...2...1...\n");
    printf("Captured packet length: %d\n", header->len);

    // Print the packet bytes
    for (i=0; i<header->len; i++) {
      printf("%02x ", packet[i]);
      if ( (i+1) % 16 == 0 ) printf("\n");
    }
    printf("\n\n-------------------------------\n\n");
  }

  // cleanup
  pcap_close(handle);
  return(0);
}