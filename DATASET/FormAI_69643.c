//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALERTS 50

typedef struct {
    char ip[16];
    char timestamp[20];
    char message[100];
} Alert;

Alert alerts[MAX_ALERTS]; // array of alerts
int numAlerts = 0; // current number of alerts

void addAlert(char *ip, char *timestamp, char *message) {
    // add new alert to array
    Alert alert;
    strncpy(alert.ip, ip, sizeof(alert.ip));
    strncpy(alert.timestamp, timestamp, sizeof(alert.timestamp));
    strncpy(alert.message, message, sizeof(alert.message));
    alerts[numAlerts] = alert;
    numAlerts++;

    // print out alert details
    printf("Alert: %s %s %s\n", ip, timestamp, message);
}

int main(int argc, char **argv) {
    // mock intrusion detection
    addAlert("192.168.1.1", "2021-01-01 12:00:00", "Connection attempt from blacklisted IP");
    addAlert("192.168.1.2", "2021-01-02 12:00:00", "Multiple failed login attempts from same IP");
    addAlert("192.168.1.3", "2021-01-03 12:00:00", "Unusual network traffic detected");

    // print out all alerts
    printf("All alerts:\n");
    for (int i = 0; i < numAlerts; i++) {
        printf("%s %s %s\n", alerts[i].ip, alerts[i].timestamp, alerts[i].message);
    }

    return 0;
}