//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ssid[20];
    int signal_strength;
} AccessPoint;

void printAccessPoints(AccessPoint* ap_list, int num_ap) {
    printf("Number of Access Points: %d\n", num_ap);
    for (int i=0; i<num_ap; i++) {
        printf("SSID: %s \t Signal Strength: %d dBm\n", ap_list[i].ssid, ap_list[i].signal_strength);
    }
}

int main() {
    AccessPoint ap_list[10];
    int num_ap = 0;

    // Simulating the detection of access points
    strcpy(ap_list[0].ssid, "MyHomeNetwork");
    ap_list[0].signal_strength = -56;
    num_ap++;

    strcpy(ap_list[1].ssid, "OfficeNetwork");
    ap_list[1].signal_strength = -78;
    num_ap++;

    strcpy(ap_list[2].ssid, "PublicWifi");
    ap_list[2].signal_strength = -90;
    num_ap++;

    // Printing the detected access points
    printAccessPoints(ap_list, num_ap);

    return 0;
}