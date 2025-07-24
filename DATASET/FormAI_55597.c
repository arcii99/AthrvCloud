//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  char *device;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  char filter_exp[] = "port 23";
  bpf_u_int32 mask;
  bpf_u_int32 net;
  struct pcap_pkthdr header;
  const u_char *packet;

  // Look up device
  device = pcap_lookupdev(errbuf);
  if (device == NULL) {
    printf("Couldn't find default device: %s\n", errbuf);
    return 1;
  }
  printf("Device: %s\n", device);

  // Get network and mask
  if (pcap_lookupnet(device, &net, &mask, errbuf) == -1) {
    printf("Couldn't get netmask for device %s: %s\n", device, errbuf);
    net = 0;
    mask = 0;
  }

  // Open device for capture
  handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Couldn't open device %s: %s\n", device, errbuf);
    return 1;
  }

  // Compile filter expression
  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    printf("Couldn't parse filter %s: %s\n", filter_exp,
           pcap_geterr(handle));
    return 1;
  }

  // Apply filter expression
  if (pcap_setfilter(handle, &fp) == -1) {
    printf("Couldn't install filter %s: %s\n", filter_exp,
           pcap_geterr(handle));
    return 1;
  }

  // Capture packets
  while (1) {
    packet = pcap_next(handle, &header);
    if (packet != NULL) {
      printf("Packet Captured!\n");
      printf("Packet length: %d\n", header.len);
      printf("\n");
    }
  }

  // Close the handle
  pcap_close(handle);
  return 0;
}