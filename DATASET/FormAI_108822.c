//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: Sherlock Holmes
// It was a foggy evening in London, and as I sat in my dimly lit office
// I knew I had to find the culprit responsible for the missing packets.
// The only clue I had was a packet sniffer log, which I analyzed with
// the help of pcap library.

#include <stdio.h>
#include <pcap.h>

void print_pkt_info(u_char *user, const struct pcap_pkthdr *hdr, const u_char *pkt) {
  // Extract packet information from header and data
  printf("Packet length: %d\n", hdr->len);
  
  // Iterate over packet bytes and print hexadecimal values
  for (int i=0; i<hdr->len; i++) {
    printf("%02x ", pkt[i]);
    if ((i+1) % 16 == 0) printf("\n"); // newline after every 16 bytes
  }
  printf("\n\n");
}

int main() {
  // Declare variables
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  struct bpf_program fp;
  char filter_exp[] = "tcp port 80"; // HTTP traffic
  bpf_u_int32 net, mask;

  // Find a suitable network interface to sniff on
  char *dev = pcap_lookupdev(errbuf);
  if (dev == NULL) {
    fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
    return 2;
  }
  
  // Fetch network and mask properties of the interface
  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Can't get netmask for device %s\n", dev);
    net = 0;
    mask = 0;
  }

  // Open network interface in promiscuous mode
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return 2;
  }

  // Compile and apply packet filter
  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 2;
  }
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return 2;
  }

  // Capture packets with callback function
  pcap_loop(handle, -1, print_pkt_info, NULL);

  // Cleanup
  pcap_freecode(&fp);
  pcap_close(handle);
  
  return 0;
}