//FormAI DATASET v1.0 Category: Firewall ; Style: retro
#include<stdio.h>
#include<string.h>

struct packet{
    char src_ip[16];
    char dest_ip[16];
    int src_port;
    int dest_port;
    char protocol[4];
    char message[256];
    int is_valid;
};

int main(){
    struct packet incoming_packet;
    strcpy(incoming_packet.src_ip, "192.168.1.10");
    strcpy(incoming_packet.dest_ip, "192.168.1.15");
    incoming_packet.src_port = 3000;
    incoming_packet.dest_port = 80;
    strcpy(incoming_packet.protocol, "TCP");
    strcpy(incoming_packet.message, "GET /index.html HTTP/1.1");
    incoming_packet.is_valid = 0;
    char rule_src_ip[16] = "192.168.1.10";
    char rule_dest_ip[16] = "192.168.1.15";
    int rule_src_port = 3000;
    int rule_dest_port = 80;
    char rule_protocol[4] = "TCP";
    int is_valid_rule = 1;
    printf("Incoming packet: \n");
    printf("Source IP: %s\n", incoming_packet.src_ip);
    printf("Destination IP: %s\n", incoming_packet.dest_ip);
    printf("Source Port: %d\n", incoming_packet.src_port);
    printf("Destination Port: %d\n", incoming_packet.dest_port);
    printf("Protocol: %s\n", incoming_packet.protocol);
    printf("Message: %s\n", incoming_packet.message);
    if(strcmp(incoming_packet.src_ip, rule_src_ip) == 0 && 
       strcmp(incoming_packet.dest_ip, rule_dest_ip) == 0 &&
       incoming_packet.src_port == rule_src_port &&
       incoming_packet.dest_port == rule_dest_port &&
       strcmp(incoming_packet.protocol, rule_protocol) == 0 &&
       is_valid_rule){
        incoming_packet.is_valid = 1;
    }
    if(incoming_packet.is_valid){
        printf("Packet allowed.\n");
        // Code for allowing the packet to pass through the firewall
    }
    else{
        printf("Packet blocked.\n");
        // Code for blocking the packet
    }
    return 0;
}