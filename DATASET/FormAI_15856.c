//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LEVELS 4
#define MAX_BAR_LENGTH 20
#define MAX_NETWORKS 10
#define MAX_SSID_LENGTH 20

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int strength;
} Network;

char* signal_bar(int level) {
    int segments = floor(level / (100 / MAX_LEVELS));
    if (segments == 0) {
        segments = 1;
    }
    char* bar = malloc(sizeof(char) * (MAX_BAR_LENGTH + 1));
    memset(bar, '|', MAX_BAR_LENGTH);
    strncpy(bar, "                ", segments);
    bar[MAX_BAR_LENGTH] = '\0';
    return bar;
}

void list_networks(Network *networks, int count) {
    printf("\nDiscovered networks:\n");
    for (int i = 0; i < count; i++) {
        printf("\nSSID: %s\n", networks[i].ssid);
        printf("Strength: %d%% %s\n", networks[i].strength, signal_bar(networks[i].strength));
    }
}

void analyze_signals(Network *networks, int count) {
    for (int i = 0; i < count; i++) {
        int strength = rand() % 100 + 1;
        networks[i].strength = strength;
    }
    list_networks(networks, count);
}

int main() {
    Network networks[MAX_NETWORKS] = {{"Wi-Fi 1", 0}, {"Wi-Fi 2", 0}, {"Wi-Fi 3", 0}, {"Wi-Fi 4", 0}, {"Wi-Fi 5", 0}, {"Wi-Fi 6", 0}, {"Wi-Fi 7", 0}, {"Wi-Fi 8", 0}, {"Wi-Fi 9", 0}, {"Wi-Fi 10", 0}};
    analyze_signals(networks, MAX_NETWORKS);
    return 0;
}