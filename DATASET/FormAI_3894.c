//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pcap.h>

#define PCAP_BUF_SIZE 1024
#define PCAP_TIMEOUT_MS 1000

const char *filter = "tcp and port 80"; // filter for HTTP traffic

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet_data) {
  printf("Packet captured!\n");
  // print packet information
}

int main(int argc, char **argv) {
  int status;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  bpf_u_int32 mask, net;
  const u_char *packet;
  struct pcap_pkthdr header;
  char *dev = pcap_lookupdev(errbuf);

  if (dev == NULL) {
    fprintf(stderr, "Error finding default device: %s\n", errbuf);
    return EXIT_FAILURE;
  }

  printf("Using device: %s\n", dev);

  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Error getting network information for device %s: %s\n", dev, errbuf);
    return EXIT_FAILURE;
  }

  handle = pcap_open_live(dev, BUFSIZ, 1, PCAP_TIMEOUT_MS, errbuf);

  if (handle == NULL) {
    fprintf(stderr, "Error opening device %s: %s\n", dev, errbuf);
    return EXIT_FAILURE;
  }

  if (pcap_compile(handle, &fp, filter, 0, net) == -1) {
    fprintf(stderr, "Error compiling filter: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Error setting filter: %s\n", pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  printf("Packet monitoring started!\n");

  pcap_loop(handle, -1, packet_handler, NULL); // capture packets indefinitely

  pcap_close(handle);

  return EXIT_SUCCESS;
}