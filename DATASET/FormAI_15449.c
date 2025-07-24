//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

int main(int argc, char **argv) {
  char *device;
  char error_buffer[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program filter;
  char filter_exp[] = "tcp port 80";
  bpf_u_int32 subnet_mask, ip;
  struct pcap_pkthdr header;
  const u_char *packet;

  device = pcap_lookupdev(error_buffer);
  if (device == NULL) {
    printf("Failed to find a suitable device.\n");
    return 1;
  }

  if (pcap_lookupnet(device, &ip, &subnet_mask, error_buffer) == -1) {
    printf("Failed to get device information.\n");
    return 1;
  }

  handle = pcap_open_live(device, BUFSIZ, 1, 1000, error_buffer);
  if (handle == NULL) {
    printf("Failed to open device.\n");
    return 1;
  }

  if (pcap_compile(handle, &filter, filter_exp, 0, ip) == -1) {
    printf("Failed to compile filter.\n");
    return 1;
  }

  if (pcap_setfilter(handle, &filter) == -1) {
    printf("Failed to apply filter.\n");
    return 1;
  }

  printf("Listening on %s...\n", device);

  while (pcap_next_ex(handle, &header, &packet) == 1) {
    printf("Received a packet with length of %d.\n", header.len);
  }

  pcap_close(handle);
  return 0;
}