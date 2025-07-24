//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_ATTACKS 1000

int main() {
    int attack_count = 0;
    int i = 0;

    while (i < MAX_ATTACKS) {
        // Simulating incoming network traffic to the Intrusion Detection System
        printf("Listening for network traffic...\n");
        int has_attack = rand() % 2;

        if (has_attack) {
            attack_count++;
            if (attack_count == 1) {
                printf("\nINTRUSION ALERT: %d attack detected\n", attack_count);
            } else {
                printf("\nINTRUSION ALERT: %d attacks detected\n", attack_count);
            }
        }

        i++;
    }

    if (attack_count == 0) {
        printf("\nSystem secure. No attacks detected.\n");
    }

    return 0;
}