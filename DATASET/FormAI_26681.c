//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL_STRENGTH 100

/* Function to calculate the strength of Wi-Fi signal */
int calculate_signal_strength(int signal_strength)
{
    int wifi_strength_percentage = signal_strength*100/MAX_SIGNAL_STRENGTH;
    return wifi_strength_percentage;
}

int main()
{
    int signal_strength;
    char wifi_name[20];

    printf("Enter the Wi-Fi signal strength: ");
    scanf("%d", &signal_strength);

    if (signal_strength > MAX_SIGNAL_STRENGTH)
    {
        printf("Invalid signal strength!\n");
        exit(0);
    }

    printf("Enter the Wi-Fi network name: ");
    scanf("%s", wifi_name);

    int wifi_strength_percentage = calculate_signal_strength(signal_strength);

    printf("Wi-Fi network %s has signal strength of %d%%.\n", wifi_name, wifi_strength_percentage);

    return 0;
}