//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 50
#define MAX_NAME_SIZE 32

struct wifi_network {
    char name[MAX_NAME_SIZE];
    int strength;
};

void analyze_wifi_strength(struct wifi_network *networks, int num_networks);

int main() {
    int num_networks;
    printf("Enter the number of Wi-Fi networks to analyze: ");
    scanf("%d", &num_networks);
    printf("Enter the names and signal strengths of the networks:\n");
    struct wifi_network networks[num_networks];
    for (int i = 0; i < num_networks; i++) {
        printf("Network %d name: ", i+1);
        scanf("%s", networks[i].name);
        printf("Network %d strength: ", i+1);
        scanf("%d", &networks[i].strength);
    }
    analyze_wifi_strength(networks, num_networks);
    return 0;
}

void analyze_wifi_strength(struct wifi_network *networks, int num_networks) {
    int strong_count = 0;
    int weak_count = 0;
    int total_strength = 0;
    for (int i = 0; i < num_networks; i++) {
        total_strength += networks[i].strength;
        if (networks[i].strength > 70) {
            strong_count++;
        } else {
            weak_count++;
        }
    }
    int average_strength = total_strength / num_networks;
    printf("Number of strong networks: %d\n", strong_count);
    printf("Number of weak networks: %d\n", weak_count);
    printf("Average signal strength: %d\n", average_strength);
}