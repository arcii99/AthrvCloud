//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int threat_level = 0;
    int sensor1_reading = rand() % 100;
    int sensor2_reading = rand() % 100;
    int sensor3_reading = rand() % 100;
    int sensor4_reading = rand() % 100;

    printf("Sensor 1 reading: %d\n", sensor1_reading);
    printf("Sensor 2 reading: %d\n", sensor2_reading);
    printf("Sensor 3 reading: %d\n", sensor3_reading);
    printf("Sensor 4 reading: %d\n", sensor4_reading);

    if (sensor1_reading > 90) {
        threat_level += 10;
        printf("Intrusion detected via Sensor 1!\n");
    }

    if (sensor2_reading > 90) {
        threat_level += 10;
        printf("Intrusion detected via Sensor 2!\n");
    }

    if (sensor3_reading > 90) {
        threat_level += 10;
        printf("Intrusion detected via Sensor 3!\n");
    }

    if (sensor4_reading > 90) {
        threat_level += 10;
        printf("Intrusion detected via Sensor 4!\n");
    }

    if (threat_level >= 30) {
        printf("Threat level is critical!\n");
        printf("Initiating countermeasures...\n");
        // Code for countermeasures here
    } else if (threat_level >= 20) {
        printf("Threat level is moderate.\n");
        printf("Monitoring sensors...\n");
        // Code for monitoring sensors here
    } else if (threat_level >= 10) {
        printf("Threat level is low.\n");
        printf("Standby mode...\n");
        // Code for standby mode here
    } else {
        printf("No threat detected.\n");
        printf("Normal mode...\n");
        // Code for normal mode here
    }

    return 0;
}