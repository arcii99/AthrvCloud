//FormAI DATASET v1.0 Category: Firewall ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    printf("The game is afoot! Let's investigate this network traffic.\n");
    
    /* Firewall rules */
    int allow_incoming = 0;
    int allow_outgoing = 1;
    
    /* Packet information */
    int src_port = 5678;
    int dst_port = 80;
    char protocol[] = "HTTP";
    
    /* Check if incoming traffic is allowed */
    if (allow_incoming == 0) {
        printf("No incoming traffic allowed. Rejecting packet.\n");
        return 0;
    }
    
    /* Check if outgoing traffic is allowed */
    if (allow_outgoing == 0) {
        printf("No outgoing traffic allowed. Rejecting packet.\n");
        return 0;
    }
    
    /* Check if packet matches firewall rules */
    if (src_port != 80 && dst_port != 80 && protocol != "HTTP") {
        printf("Packet does not match firewall rules. Rejecting packet.\n");
        return 0;
    }
    
    /* If packet passes firewall rules, allow it */
    printf("Packet allowed through firewall. Let the game continue!\n");
    return 0;
}