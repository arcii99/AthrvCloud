//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: irregular
#include <stdio.h>
#include <pcap.h>

int main()
{
  printf("Starting packet capture...\n");

  char* dev = pcap_lookupdev(NULL);
  if(dev == NULL) {
    printf("Error finding device: %s\n", pcap_geterr(NULL));
    return 1;
  }

  pcap_t* handle = pcap_open_live(dev, 65536, 1, 1000, NULL);
  if(handle == NULL) {
    printf("Error opening device: %s\n", pcap_geterr(NULL));
    return 1;
  }

  printf("Successfully opened device: %s\n", dev);

  while(1) {
    struct pcap_pkthdr* hdr;
    const u_char* pkt_data;
    int res = pcap_next_ex(handle, &hdr, &pkt_data);

    if(res < 0) {
      printf("Error reading packet: %s\n", pcap_geterr(handle));
    }
    else if(res == 0) {
      printf("Timeout reached\n");
    }
    else {
      printf("Received packet of length %d\n", hdr->len);
      for(int i = 0; i < hdr->len; i++) {
        printf("%02x ", pkt_data[i]);
      }
      printf("\n");
    }
  }

  pcap_close(handle);
  return 0;
}