//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv) {

  char *dev, errbuf[PCAP_ERRBUF_SIZE];

  /* Get a device */
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
    return(1);
  }
  printf("Device: %s\n", dev);

  /* Open the session */
  pcap_t *handle;
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return(1);
  }

  /* Filter */
  struct bpf_program fp;
  char filter_exp[] = "tcp";
  bpf_u_int32 mask;
  bpf_u_int32 net;
  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
    net = 0;
    mask = 0;
  }
  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return (1);
  }
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return (1);
  }

  /* Loop */
  pcap_loop(handle, 0, packet_handler, NULL);

  /* Close the session */
  pcap_close(handle);

  return(0);
}

void packet_handler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {

  static int count = 0;

  printf("Packet %d:\n", ++count);

  /* print the first X bytes of the packet */
  int bytes_to_display = 12;
  for (int i=0; i<bytes_to_display; i++) {
      printf("%02x ", packet[i]);
  }
  printf("\n");

}