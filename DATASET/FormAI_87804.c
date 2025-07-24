//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h> 

#define MAX_SSIDS 10
#define MAX_SSID_LEN 20

struct wifi_signal {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
};

int scan_wifi(struct wifi_signal wifi[]) {
    srand(time(NULL)); 
    int num_ssids = rand() % MAX_SSIDS;
    for(int i = 0; i < num_ssids; i++) {
        int signal = rand() % 91 - 90;
        sprintf(wifi[i].ssid, "My_Network_%d", i+1);
        wifi[i].signal_strength = signal;
    }
    return num_ssids;
}

void print_wifi(struct wifi_signal wifi[], int num_ssids) {
    printf("SSID\tSIGNAL STRENGTH\n");
    for(int i = 0; i < num_ssids; i++) {
        printf("%s\t%d%%\n", wifi[i].ssid, wifi[i].signal_strength);
    }
}

struct wifi_signal find_best_signal(struct wifi_signal wifi[], int num_ssids) {
    struct wifi_signal best_signal = wifi[0];
    for(int i = 1; i < num_ssids; i++) {
        if(wifi[i].signal_strength > best_signal.signal_strength) {
            best_signal = wifi[i];
        }
    }
    return best_signal;
}

int main() {
    struct wifi_signal wifi[MAX_SSIDS];
    int num_ssids = scan_wifi(wifi);
    print_wifi(wifi, num_ssids);
    struct wifi_signal best_signal = find_best_signal(wifi, num_ssids);
    printf("The best signal is from %s with %d%% signal strength.\n", best_signal.ssid, best_signal.signal_strength);
    return 0;
}