//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_SSID_LENGTH 32
#define MAX_NETWORKS 10
#define MAX_SIGNAL_STRENGTH 101

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} Network;

void update_networks(Network *networks, int num_networks)
{
    srand(time(NULL));
    for (int i = 0; i < num_networks; i++)
    {
        // Generate random signal strength between 0 and 100
        networks[i].signal_strength = rand() % MAX_SIGNAL_STRENGTH;

        // Give a random SSID
        char *prefixes[] = {"WiFi", "NET", "MyWiFi", "Wireless"};
        char *suffixes[] = {"1", "2", "3", "_guest", "_secure"};
        char ssid[MAX_SSID_LENGTH];

        strcpy(ssid, prefixes[rand() % 4]);
        strcat(ssid, suffixes[rand() % 5]);
        strcpy(networks[i].ssid, ssid);
    }
}

void print_networks(Network *networks, int num_networks)
{
    printf("SSID\t\tSignal Strength\n");
    for (int i = 0; i < num_networks; i++)
    {
        printf("%-15s\t%d\n", networks[i].ssid, networks[i].signal_strength);
    }
}

void analyze_signal_strength(Network *networks, int num_networks)
{
    int strongest_signal = 0;
    int weakest_signal = MAX_SIGNAL_STRENGTH;

    for (int i = 0; i < num_networks; i++)
    {
        if (networks[i].signal_strength > strongest_signal)
        {
            strongest_signal = networks[i].signal_strength;
        }

        if (networks[i].signal_strength < weakest_signal)
        {
            weakest_signal = networks[i].signal_strength;
        }
    }

    printf("Strongest Signal: %d\n", strongest_signal);
    for (int i = 0; i < num_networks; i++)
    {
        if (networks[i].signal_strength == strongest_signal)
        {
            printf("   %-15s\n", networks[i].ssid);
        }
    }

    printf("Weakest Signal: %d\n", weakest_signal);
    for (int i = 0; i < num_networks; i++)
    {
        if (networks[i].signal_strength == weakest_signal)
        {
            printf("   %-15s\n", networks[i].ssid);
        }
    }
}

int main()
{
    Network networks[MAX_NETWORKS];
    int num_networks = 5;

    // Generate some sample networks
    update_networks(networks, num_networks);

    while (1)
    {
        system("clear");
        print_networks(networks, num_networks);
        analyze_signal_strength(networks, num_networks);
        sleep(5); // pause for 5 seconds
        update_networks(networks, num_networks);
    }

    return 0;
}