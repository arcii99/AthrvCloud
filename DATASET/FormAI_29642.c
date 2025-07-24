//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct AccessPoint {
    char ssid[32];
    char bssid[18];
    int signal_strength;
};

int main() {
    struct AccessPoint ap1, ap2, ap3;
    int signal_strength1, signal_strength2, signal_strength3;
    char ssid1[32], ssid2[32], ssid3[32];
    char bssid1[18], bssid2[18], bssid3[18];

    // Simulating three access points with randomized SSID, BSSID and signal strength
    strcpy(ap1.ssid, "AccessPoint1");
    strcpy(ap1.bssid, "00:11:22:33:44:AA");
    ap1.signal_strength = rand() % 101;
    strcpy(ap2.ssid, "AccessPoint2");
    strcpy(ap2.bssid, "00:11:22:33:44:BB");
    ap2.signal_strength = rand() % 101;
    strcpy(ap3.ssid, "AccessPoint3");
    strcpy(ap3.bssid, "00:11:22:33:44:CC");
    ap3.signal_strength = rand() % 101;

    // Display information about the three access points
    printf("3 Access Points Found:\n");
    printf("SSID: %s, BSSID: %s, Signal Strength: %d%%\n", ap1.ssid, ap1.bssid, ap1.signal_strength);
    printf("SSID: %s, BSSID: %s, Signal Strength: %d%%\n", ap2.ssid, ap2.bssid, ap2.signal_strength);
    printf("SSID: %s, BSSID: %s, Signal Strength: %d%%\n", ap3.ssid, ap3.bssid, ap3.signal_strength);

    // Determine the one with the strongest signal strength
    if (ap1.signal_strength > ap2.signal_strength && ap1.signal_strength > ap3.signal_strength) {
        printf("Access Point with the strongest signal: %s\n", ap1.ssid);
    }
    else if (ap2.signal_strength > ap1.signal_strength && ap2.signal_strength > ap3.signal_strength) {
        printf("Access Point with the strongest signal: %s\n", ap2.ssid);
    }
    else if (ap3.signal_strength > ap1.signal_strength && ap3.signal_strength > ap2.signal_strength) {
        printf("Access Point with the strongest signal: %s\n", ap3.ssid);
    }

    return 0;
}