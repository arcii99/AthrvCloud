//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_PACKET_SIZE 1024

struct packet{
    char data[MAX_PACKET_SIZE];
    int size;
};

void analyze_packet(struct packet *pkt){
    // function to analyze packet data for intrusion detection
    bool has_bad_word = false;
    char *bad_words[] = {"hack", "attack", "virus", "malware", "worm"};

    for(int i=0; i<5; i++){
        if(strstr(pkt->data, bad_words[i]) != NULL){
            has_bad_word = true;
            break;
        }
    }

    if(has_bad_word){
        printf("WARNING: Intrusion detected! Packet size: %d\n", pkt->size);
        printf("Packet Data: %s\n", pkt->data);
    }
}

int main(){
    struct packet pkt1, pkt2, pkt3;

    // fill packet data with random strings
    strcpy(pkt1.data, "This is a harmless packet.");
    pkt1.size = strlen(pkt1.data);

    strcpy(pkt2.data, "This packet contains a malicious virus.");
    pkt2.size = strlen(pkt2.data);

    strcpy(pkt3.data, "This packet is an attack on your system.");
    pkt3.size = strlen(pkt3.data);

    // analyze the packets for intrusion detection
    analyze_packet(&pkt1);
    analyze_packet(&pkt2);
    analyze_packet(&pkt3);

    return 0;
}