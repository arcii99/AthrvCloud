//FormAI DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOWED_IPS 10

struct ip_addr {
    char octet1;
    char octet2;
    char octet3;
    char octet4;
};

int main() {
    int num_ips = 0;
    struct ip_addr allowed_ips[ALLOWED_IPS];

    // Adding some example IP addresses for testing
    allowed_ips[0].octet1 = 192;
    allowed_ips[0].octet2 = 168;
    allowed_ips[0].octet3 = 0;
    allowed_ips[0].octet4 = 1;
    allowed_ips[1].octet1 = 10;
    allowed_ips[1].octet2 = 0;
    allowed_ips[1].octet3 = 0;
    allowed_ips[1].octet4 = 1;
    num_ips = 2;

    // Infinite loop to listen for incoming connections
    while(1) {
        char input[256];
        printf("Enter IP address of incoming connection: ");
        fgets(input, sizeof(input), stdin);

        // Remove the newline character from the end of the input
        input[strcspn(input, "\n")] = 0;

        // Parse the IP address from the input
        char octets[4][4];
        int index = 0;
        char* ptr = strtok(input, ".");
        while(ptr != NULL && index < 4) {
            strcpy(octets[index], ptr);
            ptr = strtok(NULL, ".");
            index++;
        }

        // Validate the input
        if(index != 4) {
            printf("Invalid IP address!\n");
        } else {
            int valid = 0;

            // Check if the IP address matches any of the allowed IPs
            for(int i=0; i<num_ips; i++) {
                if(strtol(octets[0], NULL, 10) == allowed_ips[i].octet1 &&
                   strtol(octets[1], NULL, 10) == allowed_ips[i].octet2 &&
                   strtol(octets[2], NULL, 10) == allowed_ips[i].octet3 &&
                   strtol(octets[3], NULL, 10) == allowed_ips[i].octet4) {
                    valid = 1;
                    break;
                }
            }

            if(valid) {
                printf("Connection allowed!\n");
            } else {
                printf("Connection blocked!\n");
            }
        }
    }

    return 0;
}