//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LEN 32
#define MAX_BARS 5

typedef struct {
    char ssid[MAX_SSID_LEN];
    int rssi;
} wifi_network;

void display_networks(wifi_network *networks, int num_networks) {
    printf("Available Networks\n------------------\n");

    for (int i = 0; i < num_networks; i++) {
        printf("%s:\t", networks[i].ssid);

        int bars = (networks[i].rssi + 100) / 20;
        for (int j = 0; j < MAX_BARS; j++) {
            if (j < bars) {
                printf("|");
            } else {
                printf(".");
            }
        }

        printf("\n");
    }
}

int main() {
    int num_networks = 3;

    wifi_network networks[3];
    strncpy(networks[0].ssid, "MyWiFiNetwork", MAX_SSID_LEN);
    networks[0].rssi = -75;
    strncpy(networks[1].ssid, "GuestNetwork", MAX_SSID_LEN);
    networks[1].rssi = -90;
    strncpy(networks[2].ssid, "CoffeeShopWiFi", MAX_SSID_LEN);
    networks[2].rssi = -60;

    display_networks(networks, num_networks);

    return 0;
}