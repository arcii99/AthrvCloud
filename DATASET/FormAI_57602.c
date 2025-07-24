//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

// Define the data structure for packets with checksum
struct Packet {
    int id;
    int payloadLength;
    char *payload;
    int checksum;
};

// Calculate the checksum using a simple XOR operation
int calculateChecksum(char *data, int length) {
    int checksum = 0;
    for (int i = 0; i < length; i++) {
        checksum ^= data[i];
    }
    return checksum;
}

// Define the function that will be called when the checksum is ready
void onChecksumReady(int packetId, int checksum) {
    printf("Packet %d has a checksum of %d\n", packetId, checksum);
}

// Define a function that will handle the packets asynchronously
void processPacketAsync(struct Packet packet, void (*callback)(int, int)) {
    // Fake a delay of some sort
    int delay = rand() % 1000;
    // Calculate the checksum
    int checksum = calculateChecksum(packet.payload, packet.payloadLength);
    // Simulate a callback after a delay
    sleep(delay);
    callback(packet.id, checksum);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    // Create some packets to process asynchronously
    struct Packet packets[5] = {
        {1, 3, "abc", 0},
        {2, 4, "abcd", 0},
        {3, 6, "abcdef", 0},
        {4, 8, "abcdefgh", 0},
        {5, 10, "abcdefghij", 0}
    };
    // Process each packet asynchronously
    for (int i = 0; i < 5; i++) {
        processPacketAsync(packets[i], onChecksumReady);
    }
    // Wait for all packets to finish processing
    sleep(2000);
    return 0;
}