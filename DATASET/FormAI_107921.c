//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

/* Define the length of the payload and checksum */
#define LENGTH 10

/* Define the delay between each byte being processed */
#define DELAY 500000

/* Define the function to calculate the checksum */
uint8_t checksum(uint8_t *data, uint8_t len) {
    uint8_t result = 0;
    for (int i = 0; i < len; i++) {
        result ^= data[i];
    }
    return result;
}

/* Define the function to send data over the serial port */
void send_data(uint8_t *data, uint8_t len) {
    for (int i = 0; i < len; i++) {
        printf("Transmitting byte %#x\n", data[i]);
        usleep(DELAY);
    }
}

/* Define the signal handler to stop the program */
volatile bool running = true;

void sigint_handler(int sig) {
    running = false;
}

/* Define the main function */
int main(void) {
    /* Set up the signal handler */
    signal(SIGINT, sigint_handler);

    /* Generate random payload data */
    uint8_t payload[LENGTH];
    for (int i = 0; i < LENGTH; i++) {
        payload[i] = rand() % 256;
        printf("Payload byte %#x\n", payload[i]);
    }

    /* Calculate the checksum and append it to the payload */
    uint8_t cs = checksum(payload, LENGTH);
    printf("Checksum byte %#x\n", cs);
    uint8_t data[LENGTH+1];
    for (int i = 0; i < LENGTH; i++) {
        data[i] = payload[i];
    }
    data[LENGTH] = cs;

    /* Send the data over the serial port */
    while (running) {
        send_data(data, LENGTH+1);
    }

    return 0;
}