//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAX_SSID_LENGTH 32
#define MAX_BSSID_LENGTH 18

typedef struct AccessPoint {
    char ssid[MAX_SSID_LENGTH];
    char bssid[MAX_BSSID_LENGTH];
    int signal_strength;
    time_t last_updated;
} AccessPoint;

int num_access_points = 0;
AccessPoint access_points[10];
time_t last_updated = 0;

void update_access_point(char *ssid, char *bssid, int signal_strength) {
    bool found = false;
    for (int i = 0; i < num_access_points; i++) {
        if (strcmp(ssid, access_points[i].ssid) == 0 && strcmp(bssid, access_points[i].bssid) == 0) {
            access_points[i].signal_strength = signal_strength;
            access_points[i].last_updated = time(NULL);
            found = true;
            break;
        }
    }

    if (!found) {
        if (num_access_points < 10) {
            AccessPoint new_access_point;
            strcpy(new_access_point.ssid, ssid);
            strcpy(new_access_point.bssid, bssid);
            new_access_point.signal_strength = signal_strength;
            new_access_point.last_updated = time(NULL);
            access_points[num_access_points] = new_access_point;
            num_access_points++;
        } else {
            time_t oldest_time = time(NULL);
            int oldest_index = -1;
            for (int i = 0; i < num_access_points; i++) {
                if (access_points[i].last_updated < oldest_time) {
                    oldest_time = access_points[i].last_updated;
                    oldest_index = i;
                }
            }
            if (oldest_index != -1) {
                AccessPoint new_access_point;
                strcpy(new_access_point.ssid, ssid);
                strcpy(new_access_point.bssid, bssid);
                new_access_point.signal_strength = signal_strength;
                new_access_point.last_updated = time(NULL);
                access_points[oldest_index] = new_access_point;
            }
        }
    }
}

double calculate_distance(double signal_strength, double frequency) {
    double exp = (27.55 - (20 * log10(frequency)) + fabs(signal_strength)) / 20.0;
    return pow(10.0, exp);
}

void print_access_points() {
    printf("+------------------------------------------+\n");
    printf("| %-15s | %-17s | %-7s |\n", "SSID", "BSSID", "Signal");
    printf("+------------------------------------------+\n");
    for (int i = 0; i < num_access_points; i++) {
        AccessPoint ap = access_points[i];
        double distance = calculate_distance(ap.signal_strength, 2437);
        printf("| %-15s | %-17s | %-5d dBm | %-7.2f m |\n", ap.ssid, ap.bssid, ap.signal_strength, distance);
    }
    printf("+------------------------------------------+\n");
}

int main() {
    printf("Scanning for access points...\n");
    sleep(3);
    while (1) {
        srand(time(NULL));
        int signal_strength = rand() % 100 - 50;
        char ssid[MAX_SSID_LENGTH];
        char bssid[MAX_BSSID_LENGTH];
        sprintf(ssid, "ssid%d", rand() % 10);
        sprintf(bssid, "bssid:%02x:%02x:%02x:%02x:%02x:%02x", rand() % 256, rand() % 256, rand() % 256,
                rand() % 256, rand() % 256, rand() % 256);
        update_access_point(ssid, bssid, signal_strength);

        if (time(NULL) - last_updated >= 10) {
            print_access_points();
            last_updated = time(NULL);
        }
    }
    return 0;
}