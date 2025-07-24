//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// function to calculate signal strength percentage
double calculateSignalStrength(int rssi)
{
    return ((double)((double)rssi / (double)-40) * 100);
}

int main()
{
    system("clear"); // clear console on program start

    // variables to store access point details
    char ssid[50], bssid[50];
    int channel, rssi;

    printf(" _______     ________    ________   ___        ___       ___    ________   ___  __       \n");
    printf("|   ____\\   |        |_  |_   ___| |   |      |   \\     |   |  |        \\ |   |/  /      \n");
    printf("|  |__|   ___          \\   |  |     |   |      |    \\    |   |  |         \\|   /  __  \n");
    printf("|   __|  |_  |    __    |  |  |     |   |      |  |\\ \\   |   |  |    __   ||      \\ \n");
    printf("|  |____   | |   |  |   |  |  |     |   |      |  | \\ \\  |   |  |   |  |  ||  |\\  \\   \n");
    printf("|_______|  |_|   |__|  |_|  |_____| |___|      |__|  \\_\\ |___|  |___|  |__||__| \\__\\\\n");
    printf("\n\n");

    printf("This is your very own Wi-Fi Signal Strength Analyzer!\n\n");

    // ask user for their Wi-Fi access point details
    printf("Please enter your Wi-Fi SSID: ");
    scanf("%s", ssid);
    printf("Please enter your Wi-Fi BSSID: ");
    scanf("%s", bssid);
    printf("Please enter your Wi-Fi channel: ");
    scanf("%d", &channel);
    printf("\n");

    // wait for user confirmation to start signal strength analysis
    printf("Press any key to start analyzing signal strength for Wi-Fi SSID \"%s\" on channel %d...\n", ssid, channel);
    getchar();

    while (true)
    {
        // clear console and display analyzer title on each iteration
        system("clear");
        printf("Wi-Fi Signal Strength Analyzer\n\n");

        // simulate scanning for access point signal strength
        rssi = rand() % -30 + (-90);

        // calculate signal strength percentage and display to user
        printf("Wi-Fi SSID: %s\nWi-Fi BSSID: %s\nWi-Fi Channel: %d\nSignal Strength: %.2f%%\n", ssid, bssid, channel, calculateSignalStrength(rssi));
        
        // sleep for 2 seconds before next iteration
        sleep(2);
    }

    return 0;
}