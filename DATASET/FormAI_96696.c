//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>

int main() {
    int num_messages = 0;
    int num_delivered = 0;
    int num_lost = 0;

    printf("Welcome, my Lord! Your couriers stand ready to serve.\n");
    printf("How many messages shall we send forth on this quest? ");
    scanf("%d", &num_messages);

    // Simulate message delivery
    for (int i = 1; i <= num_messages; i++) {
        int success = rand() % 2;  // 0 = lost, 1 = delivered

        if (success) {
            num_delivered++;
            printf("Courier %d hath delivered the message!\n", i);
        } else {
            num_lost++;
            printf("Alas! Courier %d hath lost the message upon the road!\n", i);
        }
    }

    // Report QoS metrics
    int qos = (float)num_delivered / num_messages * 100;
    printf("Of %d messages sent, %d were delivered and %d were lost.\n", num_messages, num_delivered, num_lost);
    printf("The quality of service was %d%%.\n", qos);

    return 0;
}