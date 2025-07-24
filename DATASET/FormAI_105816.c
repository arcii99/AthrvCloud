//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: complex
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUF_LENGTH 1024

// function to handle incoming packets
void handle_packet(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
  static int count = 1;

  printf("\nPacket number %d:\n", count);
  printf("    Length: %d bytes\n", header->len);
  
  // print out source and destination MAC addresses
  printf("    Source MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
         packet[0], packet[1], packet[2], packet[3], packet[4], packet[5]);
  printf("    Destination MAC: %02x:%02x:%02x:%02x:%02x:%02x\n",
         packet[6], packet[7], packet[8], packet[9], packet[10], packet[11]);

  // parse Ethernet type
  uint16_t eth_type = ntohs(*(uint16_t *)(packet + 12));
  printf("    Ethernet Type: %04x", eth_type);

  switch (eth_type) {
    case 0x0800:
      printf(" (IPv4)\n");
      break;
    case 0x0806:
      printf(" (ARP)\n");
      break;
    case 0x86dd:
      printf(" (IPv6)\n");
      break;
    default:
      printf("\n");
  }

  // parse IP header if present
  if (eth_type == 0x0800) {
    uint8_t ip_header_length = (*(uint8_t *)(packet + 14) & 0x0f) * 4;
    struct in_addr src_ip, dst_ip;
    char src_ip_str[BUF_LENGTH], dst_ip_str[BUF_LENGTH];
    memset(&src_ip, 0, sizeof(struct in_addr));
    memset(&dst_ip, 0, sizeof(struct in_addr));
    memcpy(&src_ip, packet + 26, sizeof(struct in_addr));
    memcpy(&dst_ip, packet + 30, sizeof(struct in_addr));
    inet_ntop(AF_INET, &src_ip, src_ip_str, BUF_LENGTH);
    inet_ntop(AF_INET, &dst_ip, dst_ip_str, BUF_LENGTH);
    printf("    Source IP: %s\n", src_ip_str);
    printf("    Destination IP: %s\n", dst_ip_str);
  }

  // parse TCP header if present
  if (eth_type == 0x0800 && *(uint8_t *)(packet + 23) == 0x06) {
    uint8_t tcp_header_length = (*(uint8_t *)(packet + 46) >> 4) * 4;
    uint16_t src_port = ntohs(*(uint16_t *)(packet + 34));
    uint16_t dst_port = ntohs(*(uint16_t *)(packet + 36));
    printf("    Source Port: %d\n", src_port);
    printf("    Destination Port: %d\n", dst_port);

    // calculate length of payload
    uint32_t payload_length = header->len - (14 + tcp_header_length);

    // print payload if present
    if (payload_length > 0) {
      printf("    Payload (%d bytes):\n", payload_length);
      for (int i = 0; i < payload_length; i++) {
        printf("%02x ", packet[14 + tcp_header_length + i]);
      }
      printf("\n");
    }
  }

  // increment packet count
  count++;
}

int main(int argc, char *argv[]) {
  char *dev = NULL;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  bpf_u_int32 mask;
  bpf_u_int32 net;

  // get network device if not specified
  if (argc == 1) {
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
      fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
      return EXIT_FAILURE;
    }
  }

  // open capture device
  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
    return EXIT_FAILURE;
  }

  // get network information
  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    fprintf(stderr, "Can't get netmask for device %s: %s\n", dev, errbuf);
    net = 0;
    mask = 0;
  }

  // set filter to capture only TCP packets
  struct bpf_program fp;
  char filter_exp[] = "tcp";
  if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
    fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return EXIT_FAILURE;
  }
  if (pcap_setfilter(handle, &fp) == -1) {
    fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
    return EXIT_FAILURE;
  }

  // start packet capture loop
  pcap_loop(handle, -1, handle_packet, NULL);

  // cleanup
  pcap_freecode(&fp);
  pcap_close(handle);

  return EXIT_SUCCESS;
}