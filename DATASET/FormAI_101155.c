//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: paranoid
#include <stdio.h>
#include <pcap.h>

void packetHandler(u_char *userData, const struct pcap_pkthdr* pkthdr, const u_char* packet) {
    int i=0;
    printf("Packet %d:\n", ++(*((int *)userData)));
    
    // Print source and destination MAC addresses
    printf("MAC Source Address: ");
    for(i=0; i<6; i++){
        printf("%02x ",packet[i]);
    }
    printf("\nMAC Destination Address: ");
    for(i=6; i<12; i++){
        printf("%02x ",packet[i]);
    }
    printf("\n");
    
    // Read IP Header
    unsigned short ip_type;
    ip_type = packet[12] << 8 | packet[13];
    if(ip_type == 0x0800){ // IPv4 Packet
        printf("IP Version: IPv4\n");
        
        int ip_header_length = ( packet[14] & 0x0f ) * 4; // Get IP Header Length
        
        printf("Source IP Address: ");
        for(i=0; i<4; i++){
            printf("%d ",packet[i+26]);
        }
        printf("\n");
        
        printf("Destination IP Address: ");
        for(i=0; i<4; i++){
            printf("%d ",packet[i+30]);
        }
        printf("\n");

        // Check for malicious packets
        unsigned int source_ip = (packet[26]<<24) | (packet[27]<<16) | (packet[28]<<8) | packet[29];
        unsigned int dest_ip = (packet[30]<<24) | (packet[31]<<16) | (packet[32]<<8) | packet[33];

        if((source_ip >= 224 && source_ip <= 239) || (dest_ip >= 224 && dest_ip <= 239)){
            printf("WARNING: Malicious packet with multicast address \n");
        }

        if(packet[24] == 0x11 || packet[24] == 0x06){
            printf("WARNING: Malicious packet with Protocol ID: %d \n", packet[24]);
        }
        
        // Read TCP/UDP Header
        unsigned short port_s, port_d;
        port_s = packet[ip_header_length + 0] << 8 | packet[ip_header_length + 1];
        port_d = packet[ip_header_length + 2] << 8 | packet[ip_header_length + 3];
        
        printf("TCP/UDP Source Port: %d\n",port_s);
        printf("TCP/UDP Destination Port: %d\n",port_d);
    }
    else if(ip_type == 0x86DD){ // IPv6 Packet
        printf("IP Version: IPv6\n");
        
        printf("Source IP Address: ");
        for(i=0; i<8; i++){
            printf("%04x:%04x:",packet[i*2+22]<<8 | packet[i*2+23], packet[i*2+24]<<8 | packet[i*2+25]);
        }
        printf("\n");
        
        printf("Destination IP Address: ");
        for(i=0; i<8; i++){
            printf("%04x:%04x:",packet[i*2+38]<<8 | packet[i*2+39], packet[i*2+40]<<8 | packet[i*2+41]);
        }
        printf("\n");
        
        // Read TCP/UDP Header
        unsigned short port_s, port_d;
        port_s = packet[54] << 8 | packet[55];
        port_d = packet[56] << 8 | packet[57];
        
        printf("TCP/UDP Source Port: %d\n",port_s);
        printf("TCP/UDP Destination Port: %d\n",port_d);
    }
    printf("\n");
}
int main(int argc, char **argv) {
    int packetCount = 0;
    char *device = argv[1];
    char errorBuffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle = pcap_open_live(device, BUFSIZ, 1, 1000, errorBuffer);
    if (handle == NULL) {
        printf("An error occured while opening live pcap session: %s\n", errorBuffer);
        return 1;
    }
    pcap_loop(handle, -1, packetHandler, (u_char *)&packetCount);
    return 0;
}