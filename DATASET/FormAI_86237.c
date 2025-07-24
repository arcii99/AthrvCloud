//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: thoughtful
#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);

int main(int argc, char *argv[]) 
{
    char *dev = NULL; // holds the device to sniff on
    char errbuf[PCAP_ERRBUF_SIZE]; // holds error messages
    pcap_t *handle; // holds the session handle
    struct bpf_program fp; // holds compiled filter expression
    char filter_exp[] = "tcp port 80"; // filter expression
    bpf_u_int32 mask; // subnet mask
    bpf_u_int32 net; // IP address of our device
    
    // obtain the device to sniff on
    dev = pcap_lookupdev(errbuf);
    
    // error handling in case no device is found
    if (dev == NULL) 
    {
        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
        return(2);
    }
    
    // obtain the network address and mask of the device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) 
    {
        fprintf(stderr, "Couldn't get netmask for device %s: %s\n", dev, errbuf);
        net = 0;
        mask = 0;
    }
    
    // open the device for capturing
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    
    // error handling in case there is an issue opening the device
    if (handle == NULL) 
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return(2);
    }
    
    // compile the filter expression
    if (pcap_compile(handle, &fp, filter_exp, 0, net) == -1) 
    {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    
    // apply the filter expression
    if (pcap_setfilter(handle, &fp) == -1) 
    {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return(2);
    }
    
    // start capturing packets
    pcap_loop(handle, 0, packet_handler, NULL);
    
    // close the session
    pcap_close(handle);
    
    return(0);
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) 
{
    const struct ether_header *ethernet; // ethernet header
    const struct iphdr *ip; // IP header
    const struct tcphdr *tcp; // TCP header
    const struct udphdr *udp; // UDP header
    const char *payload; // packet payload
    int ethernet_header_length = 14; // length of ethernet header
    int ip_header_length; // length of IP header
    int tcp_header_length; // length of TCP header
    int udp_header_length; // length of UDP header
    int payload_length; // length of packet payload
    
    // obtain ethernet header
    ethernet = (struct ether_header*)(packet);
    
    // obtain IP header
    ip = (struct iphdr*)(packet + ethernet_header_length);
    ip_header_length = ip->ihl * 4;
    
    // obtain TCP header if packet is TCP
    if(ip->protocol == IPPROTO_TCP) 
    {
        tcp = (struct tcphdr*)(packet + ethernet_header_length + ip_header_length);
        tcp_header_length = tcp->doff * 4;
        
        // obtain payload
        payload = (u_char *)(packet + ethernet_header_length + ip_header_length + tcp_header_length);
        
        // calculate payload length
        payload_length = ntohs(ip->tot_len) - (ip_header_length + tcp_header_length);
        
        // print captured packet details
        printf("-------------------------TCP PACKET-------------------------\n");
        printf("From: %s\n", inet_ntoa(*((struct in_addr*)&ip->saddr)));
        printf("To: %s\n", inet_ntoa(*((struct in_addr*)&ip->daddr)));
        printf("Source Port: %d\n", ntohs(tcp->source));
        printf("Destination Port: %d\n", ntohs(tcp->dest));
        printf("Sequence Number: %u\n", ntohl(tcp->seq));
        printf("ACK Number: %u\n", ntohl(tcp->ack_seq));
        printf("Payload Length: %d bytes\n", payload_length);
        printf("Payload:\n");
        
        // print payload data in hexadecimal format
        for(int i = 0; i < payload_length; i++)
        {
            printf("%02X", payload[i]);
        }
        
        printf("\n\n");
    }
    
    // obtain UDP header if packet is UDP
    if(ip->protocol == IPPROTO_UDP) 
    {
        udp = (struct udphdr*)(packet + ethernet_header_length + ip_header_length);
        udp_header_length = 8;
        
        // obtain payload
        payload = (u_char *)(packet + ethernet_header_length + ip_header_length + udp_header_length);
        
        // calculate payload length
        payload_length = ntohs(udp->len) - udp_header_length;
        
        // print captured packet details
        printf("-------------------------UDP PACKET-------------------------\n");
        printf("From: %s\n", inet_ntoa(*((struct in_addr*)&ip->saddr)));
        printf("To: %s\n", inet_ntoa(*((struct in_addr*)&ip->daddr)));
        printf("Source Port: %d\n", ntohs(udp->source));
        printf("Destination Port: %d\n", ntohs(udp->dest));
        printf("Payload Length: %d bytes\n", payload_length);
        printf("Payload:\n");
        
        // print payload data in hexadecimal format
        for(int i = 0; i < payload_length; i++)
        {
            printf("%02X", payload[i]);
        }
        
        printf("\n\n");
    }
}