//FormAI DATASET v1.0 Category: Firewall ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

struct packet{
    char src_ip[16];
    char dst_ip[16];
    char payload[MAX_PACKET_SIZE];
};

int main(){
    struct packet pkt;
    //initialize values
    memset(&pkt, 0, sizeof(pkt));
    strcpy(pkt.src_ip, "192.168.1.1");
    strcpy(pkt.dst_ip, "192.168.2.1");
    strcpy(pkt.payload, "some payload");

    //check if packet is valid
    if(strcmp(pkt.src_ip, "192.168.1.1") == 0 && strcmp(pkt.dst_ip, "192.168.2.1") == 0){
        //allow packet to pass through firewall
        printf("Packet allowed through firewall.\n");
    }
    else{
        //block packet
        printf("Packet blocked by firewall.\n");
    }

    return 0;
}