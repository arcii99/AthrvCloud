//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: funny
#include <stdio.h>
#include <pcap.h>

int main(int argc, char **argv) {
  char errbuf[PCAP_ERRBUF_SIZE];

  pcap_t *handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

  if (handle == NULL) {
    fprintf(stderr, "Error opening live capture: %s\n", errbuf);
    return(1);
  }

  printf("Welcome to the Packet Capturer, where we catch packets like butterflies!\n");

  struct pcap_pkthdr header;

  const u_char *packet = pcap_next(handle, &header);

  printf("Ooh, got a packet with a length of [%d]! Let's catch it!\n", header.len);

  pcap_close(handle);

  printf("Packet captured, woo hoo!\n");

  return(0);
}