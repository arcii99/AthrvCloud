//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

struct wifi_network {
    char* name;
    int signal_strength;
};

int main(int argc, char** argv) {
    struct wifi_network networks[10];

    // Simulate network signals
    for (int i = 0; i < 10; i++) {
        networks[i].name = malloc(sizeof(char) * 20);
        sprintf(networks[i].name, "Network %d", i+1);
        networks[i].signal_strength = rand() % 100;
    }

    printf("======= Wi-Fi Signal Strength Analyzer =======\n\n");

    // Display network signals
    for (int i = 0; i < 10; i++) {
        char signal_bar[30];
        int num_filled_bars = networks[i].signal_strength / 10;

        memset(signal_bar, 0, 30);
        for (int j = 0; j < num_filled_bars; j++) {
            signal_bar[j] = '|';
        }

        printf("%-15s [%-30s] %d%%\n", networks[i].name, signal_bar, networks[i].signal_strength);
    }

    printf("\n==============================================\n");

    return 0;
}