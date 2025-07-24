//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0
#define MAX_WIFI_PASSWORD_LENGTH 20
#define MAX_WIFI_NAME_LENGTH 20

typedef struct wifi_signal {
    char wifi_name[MAX_WIFI_NAME_LENGTH];
    int signal_strength;
} wifi_signal;

wifi_signal random_wifi_networks[10] = {
    {"Linksys", 70},
    {"Netgear", 85},
    {"TP-Link", 60},
    {"D-Link", 40},
    {"ASUS", 75},
    {"Belkin", 50},
    {"Xiaomi", 30},
    {"GoogleHome", 95},
    {"SamsungSmartTV", 20},
    {"AppleTV", 90}
};

void print_wifi_networks(wifi_signal wifi_networks[], int num_networks) {
    printf("\n\n======= Wi-Fi NETWORKS =======\n\n");
    for (int i = 0; i < num_networks; i++) {
        printf("%d. %s - Signal Strength: %d%%\n", i+1, wifi_networks[i].wifi_name, wifi_networks[i].signal_strength);
    }
    printf("\n==============================\n\n");
}

void measure_wifi_signal_strength(wifi_signal wifi_networks[], int num_networks) {
    printf("Measuring Wi-Fi signal strength...\n\n");
    sleep(1);
    for (int i = 0; i < num_networks; i++) {
        int random_strength = rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1) + MIN_SIGNAL_STRENGTH;
        wifi_networks[i].signal_strength = random_strength;
    }
}

void sort_wifi_networks(wifi_signal wifi_networks[], int num_networks) {
    for (int i = 0; i < num_networks - 1; i++) {
        for (int j = 0; j < num_networks - i - 1; j++) {
            if (wifi_networks[j].signal_strength < wifi_networks[j+1].signal_strength) {
                wifi_signal temp = wifi_networks[j];
                wifi_networks[j] = wifi_networks[j+1];
                wifi_networks[j+1] = temp;
            }
        }
    }
}

void connect_to_wifi(wifi_signal wifi_networks[], int num_networks) {
    int chosen_network;
    bool correct_password = false;
    char wifi_password[MAX_WIFI_PASSWORD_LENGTH];

    print_wifi_networks(wifi_networks, num_networks);

    do {
        printf("Enter the number of the Wi-Fi network you would like to connect to: ");
        scanf("%d", &chosen_network);

        if (chosen_network < 1 || chosen_network > num_networks) {
            printf("Invalid network selection. Please try again.\n");
        } else {
            do {
                printf("Enter password for %s: ", wifi_networks[chosen_network-1].wifi_name);
                scanf("%s", wifi_password);
                if (strlen(wifi_password) > MAX_WIFI_PASSWORD_LENGTH) {
                    printf("Password too long. Please enter a password between 1 - %d characters.\n", MAX_WIFI_PASSWORD_LENGTH);
                } else {
                    correct_password = true;
                    printf("\nConnecting to %s...\n\nCONNECTION SUCCESSFUL!\n\n", wifi_networks[chosen_network-1].wifi_name);
                }
            } while (!correct_password);
        }       
    } while (chosen_network < 1 || chosen_network > num_networks);
}

int main() {
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n\n");

    measure_wifi_signal_strength(random_wifi_networks, 10);
    sort_wifi_networks(random_wifi_networks, 10);
    connect_to_wifi(random_wifi_networks, 10);

    return 0;
}