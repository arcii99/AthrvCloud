//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>

// Define constants for the channel numbers
#define THROTTLE_CHANNEL 1
#define ROLL_CHANNEL 2
#define PITCH_CHANNEL 3
#define YAW_CHANNEL 4

// Define variables for channel values
int throttleValue = 0;
int rollValue = 0;
int pitchValue = 0;
int yawValue = 0;

// Function to read channel values
int readChannelValue(int channelNumber) {
    int value;
    printf("Enter value for channel %d: ", channelNumber);
    scanf("%d", &value);
    return value;
}

// Function to print channel values
void printChannelValue(int channelNumber, int value) {
    printf("Channel %d: %d\n", channelNumber, value);
}

// Main function
int main() {
    // Read channel values
    throttleValue = readChannelValue(THROTTLE_CHANNEL);
    rollValue = readChannelValue(ROLL_CHANNEL);
    pitchValue = readChannelValue(PITCH_CHANNEL);
    yawValue = readChannelValue(YAW_CHANNEL);
    
    // Print channel values
    printChannelValue(THROTTLE_CHANNEL, throttleValue);
    printChannelValue(ROLL_CHANNEL, rollValue);
    printChannelValue(PITCH_CHANNEL, pitchValue);
    printChannelValue(YAW_CHANNEL, yawValue);
    
    return 0;
}