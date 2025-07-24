//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complex
#include <stdio.h>
#include <pcap.h>

#define ETH_HEADER_LEN 14

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet);

int main(int argc, char **argv){

  pcap_t *descr;
  char errbuf[PCAP_ERRBUF_SIZE];
  struct bpf_program filter;
  char filter_exp[] = "port 80";
  bpf_u_int32 maskp;
  bpf_u_int32 netp;
  int num_packets = -1;

  // Retrieve the device to capture traffic
  char *device = pcap_lookupdev(errbuf);
  if(device == NULL){
    printf("Error finding device: %s\n", errbuf);
    return 1; 
  }

  // Open the device
  descr = pcap_open_live(device, BUFSIZ, 0, -1, errbuf);
  if(descr == NULL){
    printf("Error opening device: %s\n", errbuf);
    return 1;
  }

  // Compile the filter expression
  if(pcap_compile(descr, &filter, filter_exp, 0, netp) == -1){
    printf("Error compiling filter: %s\n", pcap_geterr(descr));
    return 1;
  }

  // Set the filter
  if(pcap_setfilter(descr, &filter) == -1){
    printf("Error setting filter: %s\n", pcap_geterr(descr));
    return 1;
  }

  // Loop and capture packets indefinitely
  pcap_loop(descr, num_packets, packetHandler, NULL);

  return 0;
}

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet){

  int i = 0;
  static int count = 0;

  // Print Packet Number
  printf("Packet #%d\n", ++count);

  // Print Packet Timestamp
  printf("Timestamp: %s\n", ctime((const time_t *)&pkthdr->ts.tv_sec));

  // Parse and Print Ethernet Header
  printf("Ethernet Header:\n");
  for(i = 0; i < ETH_HEADER_LEN; i++){
    printf("%.2x ", packet[i]);
  }
  printf("\n");

  // Parse and Print IP Header
  printf("IP Header:\n");
  for(i = ETH_HEADER_LEN; i < ETH_HEADER_LEN + 20; i++){
    printf("%.2x ", packet[i]);
  }
  printf("\n");

  // Parse and Print TCP Header
  printf("TCP Header:\n");
  for(i = ETH_HEADER_LEN + 20; i < pkthdr->len; i++){
    printf("%.2x ", packet[i]);
  }
  printf("\n\n");
}