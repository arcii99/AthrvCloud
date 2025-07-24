//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_SSID_LENGTH 100
#define MAX_RESULTS 10

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int channel;
    int signal_strength;
} Network;

typedef struct {
    Network results[MAX_RESULTS];
    int count;
} ScannerResults;

ScannerResults scan_wireless_networks() {
    ScannerResults results;
    results.count = 0;

    // Simulating scanning for wireless networks
    Network network1 = {"MyNetwork", 11, -70};
    Network network2 = {"HomeWifi", 6, -80};
    Network network3 = {"StarbucksWiFi", 1, -85};
    Network network4 = {"PublicWiFi", 9, -75};
    Network network5 = {"SecureNetwork", 5, -90};

    Network networks[] = {network1, network2, network3, network4, network5};
    int num_networks = sizeof(networks) / sizeof(Network);

    // Sorting networks by signal strength in descending order
    for (int i = 0; i < num_networks - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < num_networks - i - 1; j++) {
            if (networks[j].signal_strength < networks[j + 1].signal_strength) {
                Network temp = networks[j];
                networks[j] = networks[j + 1];
                networks[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    // Adding up to MAX_RESULTS networks to results
    for (int i = 0; i < num_networks && results.count < MAX_RESULTS; i++) {
        results.results[results.count] = networks[i];
        results.count++;
    }

    return results;
}

// Function to print ScannerResults
void print_scanner_results(ScannerResults results) {
    printf("Wireless Networks Found:\n");

    for (int i = 0; i < results.count; i++) {
        Network network = results.results[i];

        printf("%d. SSID: %s, Channel: %d, Signal Strength: %d\n", i + 1, network.ssid, network.channel, network.signal_strength);
    }
}

int main() {
    ScannerResults results = scan_wireless_networks();
    print_scanner_results(results);

    return 0;
}