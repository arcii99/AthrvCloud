//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function to check the network quality of service
void check_qos() {
    int speed = rand() % 100; // simulate network speed
    int latency = rand() % 500; // simulate network latency
    int jitter = rand() % 50; // simulate network jitter

    printf("Checking network performance...\n");
    printf("Speed: %d Mbps\n", speed);
    printf("Latency: %d ms\n", latency);
    printf("Jitter: %d ms\n", jitter);

    if (speed < 10) {
        printf("WARNING! Network bandwidth is critically low.\n");
    }
    if (latency > 100) {
        printf("WARNING! Network latency is too high.\n");
    }
    if (jitter > 10) {
        printf("WARNING! Network jitter is too high.\n");
    }
    if (speed >= 10 && latency <= 100 && jitter <= 10) {
        printf("Network performance is satisfactory.\n");
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator

    printf("Post-apocalyptic Network Quality of Service Monitor\n");
    printf("---------------------------------------------------\n");

    while (1) { // loop infinitely
        check_qos();
        printf("Waiting 10 seconds for next check...\n");
        sleep(10); // wait for 10 seconds before next check
    }

    return 0;
}