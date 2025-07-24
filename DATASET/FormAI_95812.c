//FormAI DATASET v1.0 Category: Firewall ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

struct packet{
    int source_port;
    int dest_port;
    int protocol;
};

void inspect_packet(struct packet pkt){
    if(pkt.source_port == 80 || pkt.dest_port == 80){
        printf("HTTP traffic detected and blocked!\n");
    }
    else if(pkt.source_port == 443 || pkt.dest_port == 443){
        printf("HTTPS traffic detected and allowed.\n");
    }
    else if(pkt.protocol == 1){
        printf("ICMP traffic detected and blocked!\n");
    }
    else if(pkt.protocol == 6){
        printf("TCP traffic detected and allowed.\n");
    }
    else if(pkt.protocol == 17){
        printf("UDP traffic detected and blocked!\n");
    }
    else{
        printf("Unknown traffic detected and blocked!\n");
    }
}

int main(){
    struct packet p1 = { 80, 4000, 6 }; //HTTP traffic
    struct packet p2 = { 443, 5000, 6 }; //HTTPS traffic
    struct packet p3 = { 1024, 5000, 1 }; //ICMP traffic
    struct packet p4 = { 6000, 3999, 6 }; //TCP traffic
    struct packet p5 = { 7000, 5000, 17 }; //UDP traffic
    struct packet p6 = { 9000, 8000, 2 }; //Unknown traffic
    
    inspect_packet(p1);
    inspect_packet(p2);
    inspect_packet(p3);
    inspect_packet(p4);
    inspect_packet(p5);
    inspect_packet(p6);

    return 0;
}