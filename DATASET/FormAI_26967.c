//FormAI DATASET v1.0 Category: Packet Capturer with pcap library ; Style: careful
#include <pcap.h>
#include <stdio.h>

void packet_handler(u_char* user_arg, const struct pcap_pkthdr* packet_header, const u_char* packet_data){
    // Displaying the packet length
    printf("Packet Length: %d\n", packet_header->len);
    
    // Displaying the source and destination MAC Addresses
    printf("Destination MAC address: ");
    for(int i=0;i<5;i++){
        printf("%02x:",packet_data[i]);
    }
    printf("%02x\n",packet_data[5]);
    printf("Source MAC address: ");
    for(int i=6;i<11;i++){
        printf("%02x:",packet_data[i]);
    }
    printf("%02x\n",packet_data[11]);
    
    // Displaying the type of protocol
    printf("Protocol : ");
    if(packet_data[12] == 0x08 && packet_data[13] == 0x00){
        printf("IP\n");
    }else if(packet_data[12] == 0x08 && packet_data[13] == 0x06){
        printf("ARP\n");
    }else if(packet_data[12] == 0x86 && packet_data[13] == 0xDD){
        printf("IPv6\n");
    }else{
        printf("Unknown Protocol\n");
    }
}


int main(int argc, char** argv){
    
    char* device_name;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t* handle;
    int snapshot_length = 1024;
    int promiscuous = 0;
    int timeout_limit = 10000;
    struct bpf_program filter;
    char filter_exp[] = "ip";
    bpf_u_int32 subnet_mask, ip_address;
    
    if(argc > 1){
        // If command line argument is provided
        device_name = argv[1];
    }else{
        // If only one device available
        device_name = pcap_lookupdev(error_buffer);
    }
    
    // Look up information for the device and network
    pcap_lookupnet(device_name,&ip_address,&subnet_mask,error_buffer);
    
    // Open the specified network interface for packet capture
    handle = pcap_open_live(device_name,snapshot_length,promiscuous,timeout_limit,error_buffer);
    
    if(handle == NULL){
        printf("Unable to open interface %s. Error %s\n", device_name, error_buffer);
        return 1;
    }
    
    // Compile the filter expression
    pcap_compile(handle,&filter,filter_exp,0,ip_address);
    pcap_setfilter(handle,&filter);
    
    // Sniff and process packets
    printf("Packet capturing started on interface '%s'\n", device_name);
    pcap_loop(handle,-1,packet_handler,NULL);
    
    // Clean up
    pcap_freecode(&filter);
    pcap_close(handle);
    
    return 0;
}