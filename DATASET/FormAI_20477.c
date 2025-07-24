//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    
    printf("Welcome to the Network Quality of Service Monitor!\n");
    printf("We'll be keeping an eye on your network so you don't have to.\n");
    printf("Let's get started...\n\n");
    
    int packets_sent = 0;
    int packets_received = 0;
    bool is_stable = true;
    
    while (true) {
        int network_strength = rand() % 101; // simulate network strength as a percentage
        
        if (network_strength < 25) {
            is_stable = false;
            printf("Oh no! Network strength has dipped below 25%...\n");
        }
        
        if (network_strength >= 25 && network_strength < 75) {
            printf("Packets sent and received successfully.\n");
            packets_sent++;
            packets_received++;
        }
        
        if (network_strength >= 75) {
            printf("Excellent! Network strength is above 75%!\n");
            packets_sent++;
            packets_received++;
        }
        
        printf("Total packets sent: %d\n", packets_sent);
        printf("Total packets received: %d\n", packets_received);
        
        if (packets_received > 0) {
            double packet_success_rate = ((double)packets_received / (double)packets_sent) * 100;
            printf("Packet success rate: %.2f%%\n", packet_success_rate);
        }
        
        if (!is_stable) {
            printf("Warning! Network is unstable. Please double-check your internet connection.\n");
        } else {
            printf("Network is stable.\n");
        }
        
        printf("\n");
        
        // wait a few seconds before repeating
        for (int i = 0; i < 3; i++) {
            printf(".");
            fflush(stdout); // make sure dots appear instantly, not all at once later
            sleep(1);
        }
        
        printf("\n\n");
        
    }
    
    return 0;
}