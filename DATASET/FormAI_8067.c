//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Wifi {
    char ssid[30];
    int signal_strength;
    int frequency;
};

int main() {
    struct Wifi wifi_array[10];
    int i, j;

    printf("Enter SSID, Signal Strength and Frequency for 10 WIFI Networks:\n");

    /* Taking input from the user for wifi details */
    for(i=0; i<10; i++) {
        printf("\n%d. Wifi Network:", i+1);

        printf("\nSSID (max 30 characters): ");
        scanf("%s", wifi_array[i].ssid);

        printf("Signal Strength (in dBm): ");
        scanf("%d", &wifi_array[i].signal_strength);

        printf("Frequency (in MHz): ");
        scanf("%d", &wifi_array[i].frequency);
    }

    /* Sorting wifi networks based on their signal strength in descending order */
    for(i=0; i<10; i++) {
        for(j=i+1; j<10; j++) {
            if(wifi_array[i].signal_strength < wifi_array[j].signal_strength) {
                struct Wifi temp = wifi_array[i];
                wifi_array[i] = wifi_array[j];
                wifi_array[j] = temp;
            }
        }
    }

    /* Displaying the sorted wifi networks */
    printf("\nSSID               Signal Strength (dBm)    Frequency (MHz)\n");
    for(i=0; i<10; i++) {
        printf("%-30s%-23d%d\n", wifi_array[i].ssid, wifi_array[i].signal_strength, wifi_array[i].frequency);
    }

    return 0;
}