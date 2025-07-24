//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIFI_STRENGTH 100
#define MIN_WIFI_STRENGTH 0

int main()
{
    int wifi_strength;
    srand(time(0));
    wifi_strength = rand() % (MAX_WIFI_STRENGTH - MIN_WIFI_STRENGTH + 1) + MIN_WIFI_STRENGTH;
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n\n");
    printf("Your current Wi-Fi signal strength is %d%%\n\n", wifi_strength);
    if (wifi_strength <= 25)
    {
        printf("Your Wi-Fi signal is very weak. Consider moving closer to the router or resetting the router.\n");
    }
    else if (wifi_strength <= 50)
    {
        printf("Your Wi-Fi signal is weak. Consider moving closer to the router or resetting the router.\n");
    }
    else if (wifi_strength <= 75)
    {
        printf("Your Wi-Fi signal strength is good. Keep up the good work!\n");
    }
    else
    {
        printf("Your Wi-Fi signal strength is excellent. Keep up the good work!\n");
    }
    return 0;
}