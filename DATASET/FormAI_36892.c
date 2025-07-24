//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: introspective
#include <pcap.h>   // Include pcap library header
#include <stdio.h>  // Include standard input and output header
#include <stdlib.h> // Include standard library header

/* Declaring custom packet handler */
void custom_packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{

   /* Printing Packet length */
   printf("Packet size: %d bytes\n", header->len);
}

int main(int argc, char const *argv[])
{

   char errbuf[PCAP_ERRBUF_SIZE]; // Declaring error buffer
   pcap_t *handle;                // Creating pcap_t handle

   /* Listening live traffic on default interface*/
   handle = pcap_open_live("eth0", BUFSIZ, 1, 1000, errbuf);

   if (handle == NULL) // Printing error if handle not created
   {
      printf("Couldn't open device %s : %s\n", "eth0", errbuf);
      return 1;
   }

   /* Start capturing packets */
   pcap_loop(handle, 0, custom_packet_handler, NULL);

   /* Close the handle */
   pcap_close(handle);

   return 0;
}