//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct wireless_network {
    char ssid[30];
    char bssid[18];
    int channel;
    bool encryption_enabled;
};

typedef struct wireless_network wifi;

void print_network_information(wifi *network) {
    printf("\n----------------------\n");
    printf("SSID: %s\n", network->ssid);
    printf("BSSID: %s\n", network->bssid);
    printf("Channel: %d\n", network->channel);
    printf("Encryption Enabled: %s\n", network->encryption_enabled ? "Yes" : "No");
    printf("----------------------\n");
}

int main() {

    wifi networks[] = {
        {"WIFI-1", "12:34:56:78:90:AB", 6, true},
        {"WIFI-2", "23:45:67:89:AB:CD", 11, false},
        {"WIFI-3", "34:56:78:90:AB:EF", 1, true},
        {"WIFI-4", "45:67:89:AB:CD:EF", 9, false},
        {"WIFI-5", "56:78:90:AB:CD:EF", 3, false}
    };

    int num_networks = sizeof(networks) / sizeof(wifi);

    for(int i=0; i<num_networks; i++) {
        print_network_information(&networks[i]);
    }

    return 0;
}