//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: cheerful
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  pcap_t *handle;        /* Session handle */
  char *dev;             /* The device to sniff on */
  char errbuf[PCAP_ERRBUF_SIZE];  /* Error string */
  struct bpf_program fp; /* The compiled filter */
  char filter_exp[] = "port 80";/* The filter expression */
  bpf_u_int32 mask;      /* Our netmask */
  bpf_u_int32 net;       /* Our IP */

  /* Define the device */
  dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    printf("Couldn't find default device: %s\n", errbuf);
    return(2);
  }
  printf("Device: %s\n", dev);

  /* Find the properties for the device */
  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    printf("Couldn't get netmask for device %s: %s\n", dev, errbuf);
    net = 0;
    mask = 0;
  }

  /* Open the session in promiscuous mode */
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    printf("Couldn't open device %s: %s\n", dev, errbuf);
    return(2);
  }

  /* Compile and apply the filter */
  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    printf("Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return(2);
  }
  if (pcap_setfilter(handle, &fp) == -1) {
    printf("Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return(2);
  }

  /* Grab a packet */
  struct pcap_pkthdr header;
  const u_char *packet;    /* The actual packet */
  packet = pcap_next(handle, &header);
  printf("Jolly Good! Packet captured successfully with pcap library!\n");

  /* And close the session */
  pcap_close(handle);
  return(0);
}