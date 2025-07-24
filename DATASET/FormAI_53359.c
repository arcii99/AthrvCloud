//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: romantic
#include <stdio.h>
#include <pcap.h>

int main(int argc, char *argv[]) {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;                /* Session handle */
  struct bpf_program fp;         /* The compiled filter */
  char filter_exp[] = "udp";     /* The filter expression */
  bpf_u_int32 mask;              /* Our netmask */
  bpf_u_int32 net;               /* Our IP */
  struct pcap_pkthdr header;     /* The packet header */
  const u_char *packet;          /* The actual packet */

  if (pcap_lookupnet("eth0", &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Can't get netmask for device eth0\n");
    net = 0;
    mask = 0;
  }

  handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device eth0: %s\n", errbuf);
    return(2);
  }

  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return(2);
  }

  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return(2);
  }

  packet = pcap_next(handle, &header);
  printf("J'adore packets! %d bytes captured\n", header.len);

  pcap_close(handle);
  return(0);
}