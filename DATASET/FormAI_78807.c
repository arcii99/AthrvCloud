//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Global variable for the QoS score
int qos_score = 100;

// Function to decrease QoS score randomly
void decrease_qos() {
    int rand_num = rand() % 10 + 1; // Generate random number between 1 and 10
    qos_score -= rand_num;
    if (qos_score < 0)
        qos_score = 0;
}

// Function to increase QoS score when signal is received
void increase_qos(int sig) {
    if (sig == SIGUSR1)
        qos_score += 10;
    else if (sig == SIGUSR2)
        qos_score += 5;
    else if (sig == SIGINT)
        qos_score -= 10;
    if (qos_score > 100)
        qos_score = 100;
}

// Main function
int main() {
    signal(SIGUSR1, increase_qos);
    signal(SIGUSR2, increase_qos);
    signal(SIGINT, increase_qos);

    printf("Starting QoS monitor program...\n");

    while (1) {
        // Decrease QoS score randomly every 5 seconds
        sleep(5);
        decrease_qos();

        if (qos_score <= 30) {
            printf("WARNING: QoS score is %d, network is severely degraded.\n", qos_score);
            system("echo 'QoS score is low' | wall"); // Send message to all users
        }
        else if (qos_score <= 60) {
            printf("ALERT: QoS score is %d, network quality is poor.\n", qos_score);
        }
        else {
            printf("QoS score is %d, network quality is good.\n", qos_score);
        }
    }

    return 0;
}