//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEVICES 10
#define MAX_SCAN_RESULTS 20

struct scan_result_t {
    char ssid[64];
    int signal_strength;
};

struct device_t {
    char ssid[64];
    int num_scan_results;
    struct scan_result_t scan_results[MAX_SCAN_RESULTS];
};

bool is_device_known(struct device_t known_devices[], int num_known_devices, char ssid[]) {
    for (int i = 0; i < num_known_devices; i++) {
        if (strcmp(known_devices[i].ssid, ssid) == 0) {
            return true;
        }
    }

    return false;
}

void add_device(struct device_t *known_devices, int *num_known_devices, char ssid[]) {
    if (*num_known_devices >= MAX_DEVICES) {
        printf("Maximum number of known devices reached\n");
        return;
    }

    struct device_t new_device;
    strcpy(new_device.ssid, ssid);
    new_device.num_scan_results = 0;

    known_devices[*num_known_devices] = new_device;
    *num_known_devices += 1;

    printf("New device added: %s\n", ssid);
}

void add_scan_result(struct device_t *known_devices, int num_known_devices, char ssid[], struct scan_result_t scan_result) {
    for (int i = 0; i < num_known_devices; i++) {
        if (strcmp(known_devices[i].ssid, ssid) == 0) {
            if (known_devices[i].num_scan_results >= MAX_SCAN_RESULTS) {
                printf("Maximum number of scan results for device reached\n");
                return;
            }

            known_devices[i].scan_results[known_devices[i].num_scan_results] = scan_result;
            known_devices[i].num_scan_results += 1;
            printf("Scan result added for device %s: %d\n", ssid, scan_result.signal_strength);
            return;
        }
    }

    printf("Device not found in known devices\n");
}

int main() {
    struct device_t known_devices[MAX_DEVICES];
    int num_known_devices = 0;

    bool is_running = true;

    while (is_running) {
        char user_input[64];
        fgets(user_input, sizeof(user_input), stdin);

        if (strcmp(user_input, "exit\n") == 0) {
            is_running = false;
        } else if (strcmp(user_input, "list\n") == 0) {
            printf("Known devices:\n");
            for (int i = 0; i < num_known_devices; i++) {
                printf("- %s\n", known_devices[i].ssid);
            }
        } else if (strncmp(user_input, "add_device ", 11) == 0) {
            char ssid[64];
            sscanf(user_input, "add_device %s", ssid);

            if (is_device_known(known_devices, num_known_devices, ssid)) {
                printf("Device already known\n");
            } else {
                add_device(known_devices, &num_known_devices, ssid);
            }
        } else if (strncmp(user_input, "add_scan_result ", 16) == 0) {
            char ssid[64];
            int signal_strength;
            sscanf(user_input, "add_scan_result %s %d", ssid, &signal_strength);

            if (!is_device_known(known_devices, num_known_devices, ssid)) {
                printf("Unknown device\n");
            } else {
                struct scan_result_t scan_result;
                strcpy(scan_result.ssid, ssid);
                scan_result.signal_strength = signal_strength;

                add_scan_result(known_devices, num_known_devices, ssid, scan_result);
            }
        } else {
            printf("Unknown command\n");
        }
    }

    return 0;
}