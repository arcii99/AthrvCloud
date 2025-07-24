//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multiplayer
#include <stdio.h>

#define PACKET_SIZE 10 //packet size for checksum calculation

//function to calculate checksum
int calcChecksum(char *packet) {
    int sum = 0;
    for(int i=0; i<PACKET_SIZE; i++) {
        sum += packet[i];
    }
    return sum % 256; //using mod 256
}

//function to send packets
void sendPacket(char *packet, int checksum, int player) {
    printf("Player %d Sent Packet: ", player); //print which player sent the packet
    for(int i=0; i<PACKET_SIZE; i++) {
        printf("%d ", packet[i]); //print the packet data
    }
    printf("Checksum: %d\n", checksum); //print the calculated checksum
}

int main() {
    char packet1[PACKET_SIZE] = {1, 1, 0, 1, 1, 0, 0, 1, 0, 1};
    char packet2[PACKET_SIZE] = {0, 1, 1, 0, 1, 1, 0, 0, 1, 0};
    char packet3[PACKET_SIZE] = {1, 0, 1, 1, 0, 1, 1, 0, 0, 1};

    int checksum1 = calcChecksum(packet1);
    int checksum2 = calcChecksum(packet2);
    int checksum3 = calcChecksum(packet3);

    //send packets to each player
    sendPacket(packet1, checksum1, 1);
    sendPacket(packet2, checksum2, 2);
    sendPacket(packet3, checksum3, 3);

    //simulate a player modifying a packet
    packet1[4] = 0;
    int newChecksum = calcChecksum(packet1);

    //print the modified packet and the new checksum
    printf("Player 1 Modified Packet: ");
    for(int i=0; i<PACKET_SIZE; i++) {
        printf("%d ", packet1[i]);
    }
    printf("New Checksum: %d\n", newChecksum);

    return 0;
}