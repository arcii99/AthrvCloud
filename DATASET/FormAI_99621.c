//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NETWORKS 20
#define MAX_NAME_LENGTH 50
#define MAX_SIGNAL_STRENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int signal_strength;
} network;

void print_networks(network *networks, int num_networks) {
    printf("\n\n=== Available Networks ===\n\n");
    for(int i = 0; i < num_networks; i++) {
        printf("%d. %s (Signal Strength: %d%%)\n", i+1, networks[i].name, networks[i].signal_strength);
    }
    printf("\n");
}

void analyze_networks(network *networks, int num_networks) {
    char input[MAX_NAME_LENGTH];
    int choice = 0;
    while(choice <= 0 || choice > num_networks) {
        printf("Enter the number of the network you would like to analyze: ");
        fflush(stdout);
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);
    }
    network chosen_network = networks[choice-1];
    printf("\n\nAnalyzing network: %s (Signal Strength: %d%%)\n\n", chosen_network.name, chosen_network.signal_strength);
    if(chosen_network.signal_strength < 25) {
        printf("Signal strength is very weak. Try moving closer to the access point.\n");
    } else if(chosen_network.signal_strength < 50) {
        printf("Signal strength is weak. Consider moving closer to the access point.\n");
    } else if(chosen_network.signal_strength < 75) {
        printf("Signal strength is good. Keep your current position.\n");
    } else {
        printf("Signal strength is very good. Stay where you are!\n");
    }
}

int main() {
    int num_networks = 0;
    char input[MAX_NAME_LENGTH];
    network networks[MAX_NETWORKS];
    while(1) {
        printf("Enter the name of the network (or 'done' to finish): ");
        fflush(stdout);
        fgets(input, sizeof(input), stdin);
        for(int i = 0; i < strlen(input); i++) {
            input[i] = tolower(input[i]);
        }
        if(strcmp(input, "done\n") == 0) {
            break;
        }
        if(num_networks == MAX_NETWORKS) {
            printf("Maximum number of networks reached. Exiting.\n");
            return 1;
        }
        network new_network;
        new_network.signal_strength = rand() % MAX_SIGNAL_STRENGTH;
        strcpy(new_network.name, input);
        networks[num_networks] = new_network;
        num_networks++;
    }
    print_networks(networks, num_networks);
    analyze_networks(networks, num_networks);
    return 0;
}