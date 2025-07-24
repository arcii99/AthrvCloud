//FormAI DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int temperature;
    time_t t;
    srand((unsigned)time(&t)); // setting seed for random number generator

    while(1) { // infinite loop to keep monitoring temperature
        temperature = rand() % 100; // generate random temperature between 0 and 99 degrees Celsius
        printf("Temperature: %d degC\n", temperature);

        // Code for decentralized temperature monitoring
        // send temperature data to other nodes in the network

        // Code for receiving data from other nodes in the network
        // update local temperature data based on received data

        // Code for controlling cooling system based on temperature data
        // if temperature is too high, turn on cooling system
        // if temperature is within acceptable range, turn off cooling system

        sleep(5); // wait for 5 seconds before monitoring temperature again
    }

    return 0;
}