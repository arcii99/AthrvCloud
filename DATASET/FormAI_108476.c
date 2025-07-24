//FormAI DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char user_input[1024];
    int allowed_packets = 4;
    int packet_count = 0;

    printf("Welcome to the Firewall!\n");
    printf("How many packets are you sending today? (up to %d)\n", allowed_packets);

    while(1) {
        fgets(user_input, sizeof(user_input), stdin);
        if (strcmp(user_input, "exit\n") == 0) {
            printf("Goodbye!\n");
            break;
        } else if (atoi(user_input) <= allowed_packets && atoi(user_input) > 0) {
            packet_count += atoi(user_input);
            printf("Packet(s) accepted! You have %d packets remaining.\n", allowed_packets - packet_count);
            if (packet_count == allowed_packets) {
                printf("Firewall is now full. No more packets allowed!\n");
                break;
            }
        } else {
            printf("Invalid input. Please enter a number between 1 and %d or type 'exit' to exit.\n", allowed_packets);
        }
    }

    return 0;
}