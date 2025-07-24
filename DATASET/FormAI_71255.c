//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/* Function to randomly generate network usage values */
int generate_network_usage() {
    return rand()%100;
}

/* Main program to monitor network quality of service */
int main() {
    int network_usage[10]; // array to hold network usage values
    int i, avg_usage = 0;

    srand(time(NULL)); // initialize random seed

    /* Loop to generate network usage values */
    for(i=0; i<10; i++) {
        network_usage[i] = generate_network_usage(); // generate random value
        printf("Network usage value %d: %d\n", i+1, network_usage[i]); // print value
        avg_usage += network_usage[i]; // calculate average usage
    }

    avg_usage /= 10; // calculate final average usage

    /* Analysis of network quality of service based on average usage */
    if(avg_usage < 20) {
        printf("Great network quality of service!\n");
    } else if(avg_usage < 50) {
        printf("Acceptable network quality of service.\n");
    } else if(avg_usage < 80) {
        printf("Poor network quality of service. Consider upgrading.\n");
    } else {
        printf("Terrible network quality of service. Why are you even using this network?\n");
    }

    return 0;
}