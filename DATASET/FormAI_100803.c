//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
// Wi-Fi Signal Strength Analyzer Program
// By the Chatbot
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random signal strength between -100 to 0
int generate_signal_strength() {
    return (rand() % 101) * -1;
}

// Function to check the signal strength and return the message
char* check_signal_strength(int signal_strength) {
    if(signal_strength >= -50) {
        return "Excellent Signal Strength";
    }
    else if(signal_strength >= -60) {
        return "Good Signal Strength";
    }
    else if(signal_strength >= -70) {
        return "Fair Signal Strength";
    }
    else if(signal_strength >= -80) {
        return "Poor Signal Strength";
    }
    else {
        return "Very Poor Signal Strength";
    }
}

int main() {
    // Initializing variables
    int signal_strength;
    char* message;

    // Initializing random seed
    srand(time(NULL));

    // Generating random signal strengths and displaying the message
    for(int i=0; i<10; i++) {
        signal_strength = generate_signal_strength();
        message = check_signal_strength(signal_strength);
        printf("Signal Strength: %d | %s\n", signal_strength, message);
    }

    return 0;
}