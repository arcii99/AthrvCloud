//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_LENGTH 1024

// Function to parse the input string and populate a structure called Packet
struct Packet {
    char sourceIP[MAX_STRING_LENGTH];
    char destinationIP[MAX_STRING_LENGTH];
    char protocol[MAX_STRING_LENGTH];
};

void parsePacket(char* input, struct Packet* packet) {
    char* token;
    token = strtok(input, ",");
    strcpy(packet->sourceIP, token);
    token = strtok(NULL, ",");
    strcpy(packet->destinationIP, token);
    token = strtok(NULL, ",");
    strcpy(packet->protocol, token);
}

// Function to detect intrusion and raise an alert
void detectIntrusion(struct Packet* packet) {
    if (strcmp(packet->protocol, "ssh") == 0) {
        printf("Intrusion detected! SSH connection attempt from %s to %s\n", packet->sourceIP, packet->destinationIP);
        // Raise an alert or take some other action
    }
}

int main() {
    char input[MAX_STRING_LENGTH];
    struct Packet packet;

    // Continuously read input packets until user presses "q" to quit
    while (fgets(input, sizeof(input), stdin)) {
        if (input[0] == 'q') {
            break;
        }
        parsePacket(input, &packet);
        detectIntrusion(&packet);
    }

    return 0;
}