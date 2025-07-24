//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

#define MAX_LEVELS 10

// A struct containing information related to network traffic and QoS
typedef struct {
    int packets_sent;
    int packets_received;
    float delay;
    int jitter;
} network_info;

// A fun and quirky function to randomly generate network traffic and QoS data
network_info generate_random_network_info() {
    network_info info;
    info.packets_sent = rand() % 1000;
    info.packets_received = rand() % 1000;
    info.delay = (float)(rand() % 10000)/1000;
    info.jitter = rand() % 50;
    return info;
}

// A function to print the network information using printf in a easily readable format
void print_network_info(network_info info) {
    printf("Packets Sent: %d\n", info.packets_sent);
    printf("Packets Received: %d\n", info.packets_received);
    printf("Delay: %.3fms\n", info.delay);
    printf("Jitter: %d\n", info.jitter);
}

int main() {
    int levels[MAX_LEVELS] = {0};
    int current_level = 0;
    srand(time(0));
    printf("Starting Network Quality of Service (QoS) monitor\n");
    while(1) {
        // Generate random network information
        network_info info = generate_random_network_info();
        // Print network information
        printf("\nNetwork Information at Level %d:\n", current_level);
        print_network_info(info);
        // Change QoS level based on network information
        if(info.delay > 5.0) {
            levels[current_level] = 1; // Poor Quality
        } else if(info.delay > 2.0) {
            levels[current_level] = 2; // Average Quality
        } else {
            levels[current_level] = 3; // Good Quality
        }
        current_level++;
        if(current_level == MAX_LEVELS) {
            // Print QoS Report
            printf("\nQoS Report:\n");
            for(int i=0; i<MAX_LEVELS; i++) {
                printf("Level %d: ", i+1);
                if(levels[i] == 1) {
                    printf("Poor Quality\n");
                } else if(levels[i] == 2) {
                    printf("Average Quality\n");
                } else {
                    printf("Good Quality\n");
                }
            }
            // Reset QoS Levels
            for(int i=0; i<MAX_LEVELS; i++) {
                levels[i] = 0;
            }
            current_level = 0;
        }
        usleep(3000000); // Wait for 3 seconds before generating new network info
    }
    return 0;
}