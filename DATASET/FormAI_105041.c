//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#define MAX_PACKET_LENGTH 65536

int main(int argc, char *argv[]) {

   char *dev, errbuf[PCAP_ERRBUF_SIZE];
   pcap_t *handle;
   struct bpf_program fp;          /* holds compiled filter */
   bpf_u_int32 net;                /* IP address of our sniffing device */
   bpf_u_int32 mask;               /* subnet mask of our sniffing device */
   struct pcap_pkthdr header;      /* holds the packet header */
   const u_char *packet;           /* complete packet */

   char filter_exp[] = "udp and port 53"; /* filter expression */
   /* compile the filter expression */
   if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) {
       fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
       exit(EXIT_FAILURE);
   }

   /* apply filter */
   if (pcap_setfilter(handle, &fp) == -1) {
       fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
       exit(EXIT_FAILURE);
   }


   /* start sniffing */
   while(1) {
     packet = pcap_next(handle, &header);  /* get the next packet */
     printf("Packet length: %d\n", header.len);
     printf("Number of bytes: %d\n", header.caplen);
     printf("Packet Data:\n");
     int i;
     for (i = 0; i < header.caplen; i++) {
        printf("%02x ", *(packet+i));
        if (i%16 == 15) printf("\n");
     }
     printf("\n\n");
   }

   /* cleanup */
   pcap_freecode(&fp);
   pcap_close(handle);
   return 0;
}