//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NETWORKS 50

struct network {
    char ssid[20];
    int signal_strength;
};

char *generate_random_ssid();

int main() {
    struct network networks[MAX_NETWORKS];
    int num_networks = 0;

    // Generate some random networks
    for (int i = 0; i < 10; i++) {
        struct network net;
        strcpy(net.ssid, generate_random_ssid());
        net.signal_strength = (rand() % 100) - 50; // Generate signal strength between -50 and 49
        networks[i] = net;
        num_networks++;
    }

    // Print the list of networks
    printf("List of Wi-Fi Networks:\n");
    printf("=======================\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%s: %d%%\n", networks[i].ssid, networks[i].signal_strength);
    }

    // Calculate average signal strength
    double sum = 0;
    for (int i = 0; i < num_networks; i++) {
        sum += networks[i].signal_strength;
    }
    double average_signal_strength = sum / num_networks;

    // Calculate standard deviation
    double variance = 0;
    for (int i = 0; i < num_networks; i++) {
        double diff = networks[i].signal_strength - average_signal_strength;
        variance += pow(diff, 2);
    }
    double std_deviation = sqrt(variance / num_networks);

    // Determine which networks are below average signal strength
    printf("\nNetworks with below average signal strength:\n");
    printf("===========================================\n");
    for (int i = 0; i < num_networks; i++) {
        if (networks[i].signal_strength < average_signal_strength) {
            printf("%s: %d%%\n", networks[i].ssid, networks[i].signal_strength);
        }
    }

    // Print statistics
    printf("\nStatistics:\n");
    printf("==========\n");
    printf("Number of Networks: %d\n", num_networks);
    printf("Average Signal Strength: %.2f%%\n", average_signal_strength);
    printf("Standard Deviation: %.2f%%\n", std_deviation);

    return 0;
}

/**
 * Generates a random Wi-Fi SSID
 */
char *generate_random_ssid() {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    static const int max_ssid_length = 15;
    char *ssid = malloc(max_ssid_length + 1);
    int length = (rand() % max_ssid_length) + 1;
    for (int i = 0; i < length; i++) {
        ssid[i] = charset[rand() % strlen(charset)];
    }
    ssid[length] = '\0';
    return ssid;
}