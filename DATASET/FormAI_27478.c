//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: imaginative
#include <stdio.h>
#include <pcap.h>

int main() {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle = pcap_open_live("en0", BUFSIZ, 1, 1000, errbuf);
  if (!handle) {
    printf("Cannot open device: %s\n", errbuf);
    return -1;
  }

  struct pcap_pkthdr header;
  const u_char *packet;
  int pkt_count = 0;
  while (pkt_count < 10) {
    packet = pcap_next(handle, &header);
    if (packet) {
      printf("Packet %d captured - Length: %d\n", ++pkt_count, header.len);
    }
  }

  pcap_close(handle);
  return 0;
}