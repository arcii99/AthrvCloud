//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum size of packet

// function to check if the packet contains malicious data
int isMalicious(char packet[]) {
    int i, j;
    char keywords[4][10] = {"hack", "password", "virus", "attack"};
    // iterate over the keywords and check if they exist in the packet
    for(i=0; i < 4; i++) {
        if(strstr(packet, keywords[i])) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char packet[MAX_SIZE];
    int i, j, len, count = 0;
    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please enter the packet to be checked:\n");
    fgets(packet, MAX_SIZE, stdin); // read input packet
    len = strlen(packet);
    if(packet[len-1] == '\n') packet[len-1] = '\0'; // remove trailing newline character
    
    if(isMalicious(packet)) {
        printf("Malicious packet detected! Alerting security team...\n");
        // send alert to security team code goes here
        return 1;
    }
    printf("Packet is safe. Proceeding to next stage...");
    // code for next stage goes here
    return 0;
}