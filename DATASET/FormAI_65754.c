//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

char* SIGNAL_LEVELS[] = {"Very Weak", "Weak", "Moderate", "Strong", "Very Strong"};

typedef struct {
    char* ssid;
    int signalStrength; // Signal strength in dBm
} AccessPoint;

void printAPInfo(AccessPoint ap) {
    printf("SSID: %s\nSignal Strength: %d dBm\nSignal Level: %s\n", ap.ssid, ap.signalStrength, SIGNAL_LEVELS[ap.signalStrength/20]);
}

int main() {
    int numAPs;
    printf("Enter the number of access points: ");
    scanf("%d", &numAPs);

    AccessPoint* accessPoints = (AccessPoint*) malloc(numAPs * sizeof(AccessPoint));

    for(int i = 0; i < numAPs; i++) {
        printf("----- Access Point %d -----\n", i+1);
        printf("Enter the SSID: ");
        scanf("%s", accessPoints[i].ssid);
        printf("Enter the signal strength in dBm: ");
        scanf("%d", &accessPoints[i].signalStrength);
        printf("--------------------------\n");
    }

    // Print info for each access point
    for(int i = 0; i < numAPs; i++) {
        printf("Access Point %d:\n", i+1);
        printAPInfo(accessPoints[i]);
    }

    free(accessPoints);
    return 0;
}