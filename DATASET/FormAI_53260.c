//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
/* 

Packet Monitoring Program

Author: Claude Shannon

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <arpa/inet.h>

#define FILTER_EXP "ip" // capture only IP packets
#define SNAP_LEN 65535
#define TIME_OUT 1000

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) {

  char *dev = NULL;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  bpf_u_int32 mask, net;

  // 1. find a valid network device to capture traffic on
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
    exit(EXIT_FAILURE);
  }

  // 2. get network mask and IP
  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
    net = 0;
    mask = 0;
  }

  // 3. open network device
  handle = pcap_open_live(dev, SNAP_LEN, 1, TIME_OUT, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    exit(EXIT_FAILURE);
  }

  // 4. compile and set filter expression
  if (pcap_compile(handle, &fp, FILTER_EXP, 0, net) == -1) {
    fprintf(stderr, "Couldn't compile filter expression %s: %s\n", FILTER_EXP, pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Couldn't set filter %s: %s\n", FILTER_EXP, pcap_geterr(handle));
    exit(EXIT_FAILURE);
  }

  // 5. start packet capture loop
  pcap_loop(handle, -1, packet_handler, NULL);

  // 6. cleanup
  pcap_freecode(&fp);
  pcap_close(handle);
  printf("\nCapture complete.\n");

  return 0;
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

  static int packet_count = 0;

  // print timestamp and packet length
  printf("\nTimestamp:\t%ld.%06ld\nPacket length:\t%d\n", header->ts.tv_sec, header->ts.tv_usec, header->len);

  // print packet in hex format
  printf("Packet data:\n");
  for (int i = 0; i < header->len; i++) {
    if (i % 16 == 0) printf("\n");
    printf("%02x ", packet[i]);
  }

  // increment packet count
  packet_count++;

  printf("\nPacket count:\t%d\n", packet_count);
}