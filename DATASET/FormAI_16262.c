//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: all-encompassing
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  pcap_t *handle;      /* session handle */
  char *dev;           /* device to sniff on */
  char errbuf[PCAP_ERRBUF_SIZE];  /* error buffer */
  struct bpf_program fp;          /* compiled filter */
  char filter_exp[] = "port 80";  /* filter expression */
  bpf_u_int32 mask;    /* subnet mask */
  bpf_u_int32 net;     /* ip */
  struct pcap_pkthdr header;      /* packet header */
  const u_char *packet;           /* packet data */

  /* find a capture device */
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
    return(2);
  }
  printf("Device: %s\n", dev);

  /* get network number and mask associated with capture device */
  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
    net = 0;
    mask = 0;
  }
  printf("Net: %d\n", net);
  printf("Mask: %d\n", mask);

  /* open capture device */
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return(2);
  }

  /* compile the filter expression */
  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return(2);
  }

  /* apply the compiled filter */
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return(2);
  }

  /* loop through and capture packets */
  while (1) {
    packet = pcap_next(handle, &header);
    if (packet == NULL) { continue; }
    printf("Got a packet with length of [%d]\n", header.len);
  }

  /* cleanup */
  pcap_freecode(&fp);
  pcap_close(handle);
  printf("\nCapture complete.\n");

  return(0);
}