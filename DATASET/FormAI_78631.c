//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for QoS levels 
#define LOW_QoS 1
#define MEDIUM_QoS 2
#define HIGH_QoS 3

// Define constants for threshold values
#define LOW_THRESHOLD 30
#define MEDIUM_THRESHOLD 60

// Print welcome message
void printWelcomeMessage() {
    printf("I say, Watson, it appears we have a case to solve...\n");
    printf("We've been called in to monitor the Network Quality of Service (QoS).\n");
    printf("Our task is to identify when the QoS drops below certain thresholds.\n");
    printf("Let's get to work!\n\n");
}

// Read in network traffic data and return QoS level
int readNetworkData() {
    int totalThroughput = 0;
    int numPackets = 0;
    int avgThroughput = 0;

    // Simulate network traffic by generating random data
    for (int i = 0; i < 10; i++) {
        totalThroughput += rand()%10 + 1;
        numPackets++;
    }

    // Calculate average throughput
    if (numPackets != 0) {
        avgThroughput = totalThroughput / numPackets;
    }

    // Determine QoS level based on average throughput
    if (avgThroughput <= LOW_THRESHOLD) {
        return LOW_QoS;
    } else if (avgThroughput <= MEDIUM_THRESHOLD) {
        return MEDIUM_QoS;
    } else {
        return HIGH_QoS;
    }
}

// Print QoS result
void printQoSResult(int QoSLevel) {
    switch(QoSLevel) {
        case LOW_QoS:
            printf("The QoS has dropped to a LOW level!\n");
            break;
        case MEDIUM_QoS:
            printf("The QoS has dropped to a MEDIUM level.\n");
            break;
        case HIGH_QoS:
            printf("The QoS is currently at a HIGH level.\n");
            break;
        default:
            printf("Error: Invalid QoS level.\n");
    }
}

int main() {
    int currentQoSLevel = 0;
    int newQoSLevel = 0;

    // Print welcome message
    printWelcomeMessage();

    // Continuously monitor QoS level every 5 seconds
    while(1) {
        printf("Monitoring QoS...\n");

        // Read in network traffic data and determine QoS level
        newQoSLevel = readNetworkData();

        // Print QoS result if level has changed
        if (newQoSLevel != currentQoSLevel) {
            printQoSResult(newQoSLevel);
            currentQoSLevel = newQoSLevel;
        }

        // Wait for 5 seconds
        sleep(5);
    }

    return 0;
}