//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wifi_data {
    char ssid[20];
    int signal_strength;
};

struct wifi_data wifi_array[10];

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer\n");
    int number_of_networks;
    printf("Please enter the number of Wi-Fi networks you want to analyze (maximum 10): ");
    scanf("%d", &number_of_networks);
    if (number_of_networks < 0 || number_of_networks > 10) {
        printf("Invalid input! Exiting...\n");
        return 0;
    }
    printf("Please enter the SSID and signal strength (out of 100) of each network:\n");
    for (int i = 0; i < number_of_networks; ++i) {
        printf("Network%d: ", i+1);
        scanf("%s%d", wifi_array[i].ssid, &wifi_array[i].signal_strength);
    }
    printf("Here are the Wi-Fi networks and their signal strengths:\n");
    printf("|----------------------|\n");
    printf("| SSID        | Strength |\n");
    printf("|----------------------|\n");
    for (int i = 0; i < number_of_networks; ++i) {
        printf("| %-10s | %6d%% |\n", wifi_array[i].ssid, wifi_array[i].signal_strength);
    }
    printf("|----------------------|\n");
    int highest_strength = 0;
    char strongest_ssid[20];
    for (int i = 0; i < number_of_networks; ++i) {
        if (wifi_array[i].signal_strength > highest_strength) {
            highest_strength = wifi_array[i].signal_strength;
            strcpy(strongest_ssid, wifi_array[i].ssid);
        }
    }
    printf("The Wi-Fi network with the highest signal strength is '%s' with a strength of %d%%\n", strongest_ssid, highest_strength);
    return 0;
}