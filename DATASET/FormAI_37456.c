//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SSID_LENGTH 32 // maximum length for SSID string
#define MAX_SIGNAL_STRENGTH 100 // maximum signal strength value
#define MIN_SIGNAL_STRENGTH -100 // minimum signal strength value

// function to generate random signal strength value
int getRandSignalStrength() {
    int signalStrength = (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH;
    return signalStrength;
}

// struct to represent Wi-Fi network
struct wifi_network {
    char ssid[MAX_SSID_LENGTH]; // SSID of Wi-Fi network
    int signal_strength; // signal strength of Wi-Fi network (-100 to 100)
};

// function to print Wi-Fi network details
void printWifiNetwork(struct wifi_network network) {
    printf("SSID: %s\n", network.ssid);
    printf("Signal Strength: %d\n", network.signal_strength);
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed random number generator

    // create sample Wi-Fi networks
    struct wifi_network network1 = {"Wifi1", getRandSignalStrength()};
    struct wifi_network network2 = {"Wifi2", getRandSignalStrength()};
    struct wifi_network network3 = {"Wifi3", getRandSignalStrength()};
    struct wifi_network network4 = {"Wifi4", getRandSignalStrength()};
    struct wifi_network network5 = {"Wifi5", getRandSignalStrength()};

    // print details of all Wi-Fi networks
    printf("Details of Wi-Fi Networks:\n");
    printWifiNetwork(network1);
    printWifiNetwork(network2);
    printWifiNetwork(network3);
    printWifiNetwork(network4);
    printWifiNetwork(network5);

    // calculate average signal strength
    float avg_signal_strength = 0;
    avg_signal_strength += network1.signal_strength;
    avg_signal_strength += network2.signal_strength;
    avg_signal_strength += network3.signal_strength;
    avg_signal_strength += network4.signal_strength;
    avg_signal_strength += network5.signal_strength;
    avg_signal_strength /= 5;

    // print average signal strength
    printf("Average Signal Strength: %.2f\n", avg_signal_strength);

    return 0;
}