//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate network traffic
void simulateTraffic() {
    int r = rand() % 100; // Generate a random number between 0 and 99
    if (r < 60) { // 60% chance of success
        printf("Packet successfully delivered.\n");
    } else if (r < 80) { // 20% chance of delay
        sleep(1);
        printf("Packet delayed.\n");
    } else { // 20% chance of loss
        printf("Packet lost.\n");
    }
}

int main() {
    printf("Starting Quality of Service Monitor...\n");
    srand(time(NULL)); // Set seed for random number generator
    int packets_sent = 0;
    int packets_lost = 0;
    while(1) { // Program runs until interrupted
        printf("Sending packet...\n");
        simulateTraffic(); // Simulate network traffic
        packets_sent++;
        int success_rate = (packets_sent - packets_lost) * 100 / packets_sent; // Calculate success rate
        printf("Success rate: %d%%\n", success_rate);
        if(success_rate < 50) { // If success rate drops below 50%, take action
            printf("Warning! Network Quality of Service dropping below 50%%.\n");
            // Call IT department for assistance
            printf("Calling IT department...\n");
            // IT department responds
            printf("IT department: Hello, how can I assist you?\n");
            printf("User: Our network Quality of Service is dropping below 50%%, can you help?\n");
            printf("IT department: Sure, I'll take a look. Have you tried turning it off and on again?\n");
            printf("User: Yes, but it didn't work.\n");
            printf("IT department: Hmmm, have you tried hitting it with a hammer?\n");
            printf("User: What?! No, I haven't tried that.\n");
            printf("IT department: Ha! Just kidding. I'll take a closer look. Hold on...\n");
            printf("IT department: Ah, I see the problem. Your cat has been chewing on the network cable.\n");
            printf("User: What?! I don't even have a cat.\n");
            printf("IT department: Oh, sorry. Wrong ticket.\n");
            printf("IT department: Anyway, I've found the issue. I'll fix it right away.\n");
            printf("User: Thank you so much!\n");
            printf("Success rate: %d%%\n", success_rate); // Show success rate after fixing issue
        }
        printf("Press CTRL+C to exit program.\n");
        sleep(2); // Wait 2 seconds before sending next packet
        printf("\n");
    }
    return 0;
}