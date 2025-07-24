//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_WIFI_SIGNAL_STRENGTH 100
#define MIN_WIFI_SIGNAL_STRENGTH 0
#define ANALYZE_INTERVAL_SECONDS 10

int main()
{
    srand(time(NULL));
    int signal_strength = 0;
    char command[1024];

    printf("WiFi Signal Strength Analyzer: Press Ctrl+C to exit");

    while(1)
    {
        signal_strength = rand() % MAX_WIFI_SIGNAL_STRENGTH;
        if(signal_strength < MIN_WIFI_SIGNAL_STRENGTH)
            signal_strength = MIN_WIFI_SIGNAL_STRENGTH;

        printf("\nSignal Strength: %d%%\n", signal_strength);

        if(signal_strength >= 75)
        {
            sprintf(command, "curl -X POST https://hooks.slack.com/services/T01XXXXXXX/B01XXXXXXX/XXXXXXXXXXXXXX -H 'Content-type: application/json' --data '{\"text\":\"Signal Strength is %d%%, Excellent Signal!\"}'", signal_strength);
            system(command);
        }
        else if(signal_strength >= 50 && signal_strength < 75)
        {
            sprintf(command, "curl -X POST https://hooks.slack.com/services/T01XXXXXXX/B01XXXXXXX/XXXXXXXXXXXXXX -H 'Content-type: application/json' --data '{\"text\":\"Signal Strength is %d%%, Good Signal!\"}'", signal_strength);
            system(command);
        }
        else if(signal_strength >= 25 && signal_strength < 50)
        {
            sprintf(command, "curl -X POST https://hooks.slack.com/services/T01XXXXXXX/B01XXXXXXX/XXXXXXXXXXXXXX -H 'Content-type: application/json' --data '{\"text\":\"Signal Strength is %d%%, Poor Signal! Recommend moving closer to WiFi Access Point!\"}'", signal_strength);
            system(command);
        }
        else
        {
            sprintf(command, "curl -X POST https://hooks.slack.com/services/T01XXXXXXX/B01XXXXXXX/XXXXXXXXXXXXXX -H 'Content-type: application/json' --data '{\"text\":\"Signal Strength is %d%%, Extremely Poor Signal!\"}'", signal_strength);
            system(command);
        }

        sleep(ANALYZE_INTERVAL_SECONDS);
    }

    return 0;
}