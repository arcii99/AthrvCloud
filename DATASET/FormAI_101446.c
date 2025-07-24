//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MAC_ADDR_LEN 17 // 6 bytes in MAC address plus 5 colons and null terminator
#define MAX_SSID_LEN 33 // 32 char SSID plus null terminator
#define MAX_DATA_LEN 1024 // Maximum data length for reading from /proc/net/wireless
#define MAX_DEVICES 10 // Maximum number of devices we will analyze
#define REFRESH_INTERVAL 2 // Interval (in seconds) between refreshes of signal strength data

enum {
    LEVEL_NONE,
    LEVEL_POOR,
    LEVEL_FAIR,
    LEVEL_GOOD,
    LEVEL_EXCELLENT
};

typedef struct {
    int level;
    char* label;
} wifi_strength_t;

wifi_strength_t wifi_strength_labels[5] = {
    {LEVEL_NONE, "NONE"},
    {LEVEL_POOR, "POOR"},
    {LEVEL_FAIR, "FAIR"},
    {LEVEL_GOOD, "GOOD"},
    {LEVEL_EXCELLENT, "EXCELLENT"}
};

typedef struct {
    char mac_address[MAX_MAC_ADDR_LEN];
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} wifi_device_t;

wifi_device_t devices[MAX_DEVICES];
int num_devices = 0;

void parse_wifi_data(char* data) {
    char* line = strtok(data, "\n");

    while (line != NULL) {
        if (strstr(line, "Inter-") != NULL) {
            line = strtok(NULL, "\n"); // Skip the "face" line
            continue;
        }

        char* mac_addr_str = strtok(line, " ");
        char* ssid_str = strtok(NULL, " ");
        char* signal_str = strtok(NULL, " ");

        if (mac_addr_str == NULL || ssid_str == NULL || signal_str == NULL) {
            fprintf(stderr, "Failed to parse wifi data line: %s\n", line);
            continue;
        }

        if (strcmp(ssid_str, "0") == 0) {
            ssid_str = "<hidden>";
        }

        wifi_device_t device;
        strncpy(device.mac_address, mac_addr_str, MAX_MAC_ADDR_LEN);
        strncpy(device.ssid, ssid_str, MAX_SSID_LEN);
        device.signal_strength = atoi(signal_str);

        devices[num_devices] = device;
        num_devices++;

        if (num_devices >= MAX_DEVICES) {
            break;
        }

        line = strtok(NULL, "\n");
    }
}

void get_wifi_data() {
    FILE* fp;
    char path[50];

    for (int i = 0; i < num_devices; i++) {
        sprintf(path, "/proc/net/wireless/%s", devices[i].mac_address);

        fp = fopen(path, "r");

        if (fp == NULL) {
            fprintf(stderr, "Failed to open wifi device file %s\n", path);
            continue;
        }

        char data[MAX_DATA_LEN];

        if (fgets(data, MAX_DATA_LEN, fp) != NULL) {
            parse_wifi_data(data);
        } else {
            fprintf(stderr, "Failed to read wifi device data for %s\n", devices[i].mac_address);
        }

        fclose(fp);  
    }
}

void clear_screen() {
    // This is platform-dependent code for clearing the screen
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void print_strength_label(int level) {
    for (int i = 0; i < 5; i++) {
        if (wifi_strength_labels[i].level == level) {
            printf("%s\t", wifi_strength_labels[i].label);
            return;
        }
    }
}

void display_wifi_data() {
    clear_screen();
    printf("SSID\t\tMAC ADDRESS\tSIGNAL STRENGTH\n");

    for (int i = 0; i < num_devices; i++) {
        printf("%s\t%s\t%d dBm\t", devices[i].ssid, devices[i].mac_address, devices[i].signal_strength);

        if (devices[i].signal_strength <= -90) {
            print_strength_label(LEVEL_NONE);
        } else if (devices[i].signal_strength <= -80) {
            print_strength_label(LEVEL_POOR);
        } else if (devices[i].signal_strength <= -70) {
            print_strength_label(LEVEL_FAIR);
        } else if (devices[i].signal_strength <= -60) {
            print_strength_label(LEVEL_GOOD);
        } else {
            print_strength_label(LEVEL_EXCELLENT);
        }

        printf("\n");
    }
}

int main() {
    devices[0].mac_address[0] = 'w'; // This is a sample device, replace with your own
    devices[0].mac_address[1] = 'l'; // This is a sample device, replace with your own
    devices[0].mac_address[2] = 'a'; // This is a sample device, replace with your own
    devices[0].mac_address[3] = 'n'; // This is a sample device, replace with your own
    devices[0].mac_address[4] = '0'; // This is a sample device, replace with your own
    devices[0].mac_address[5] = '\0'; // This is a sample device, replace with your own
    num_devices = 1;

    while (1) {
        get_wifi_data();
        display_wifi_data();
        sleep(REFRESH_INTERVAL);
    }

    return 0;
}