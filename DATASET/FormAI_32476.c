//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define SCAN_INTERVAL 5

struct wifi_network {
    char ssid[32];
    char bssid[18];
    int signal_strength;
};

// Function to check if two networks are the same
bool is_same_network(struct wifi_network network1, struct wifi_network network2) {
    if (strcmp(network1.ssid, network2.ssid) == 0 && strcmp(network1.bssid, network2.bssid) == 0) {
        return true;
    }
    return false;
}

// Function to print a wifi network
void print_network(struct wifi_network network) {
    printf("SSID: %s\nBSSID: %s\nSignal Strength: %d\n", network.ssid, network.bssid, network.signal_strength);
}

// Function to scan for wifi networks
void* scan_networks(void* arg) {
    printf("Scanning for wifi networks...\n");
    
    struct wifi_network networks[10]; // Maximum of 10 networks can be displayed
    int num_networks = 0;
    
    while (true) {
        FILE* fp = popen("iwlist wlan0 scan", "r"); // Change wlan0 to the interface name on your system
        
        if (fp == NULL) {
            printf("Failed to scan for wifi networks\n");
            return NULL;
        }
        
        char buffer[BUFFER_SIZE];
        bool network_found = false;
        struct wifi_network new_network;
        
        while (fgets(buffer, BUFFER_SIZE, fp)) {
            if (strstr(buffer, "ESSID:") != NULL) {
                char* ssid_start = strstr(buffer, "\"") + 1;
                char* ssid_end = strstr(ssid_start, "\"");
                strncpy(new_network.ssid, ssid_start, ssid_end - ssid_start);
            }
            
            if (strstr(buffer, "Address:") != NULL) {
                char* bssid_start = strstr(buffer, ":") + 2;
                strncpy(new_network.bssid, bssid_start, 17);
            }
            
            if (strstr(buffer, "Signal level=") != NULL) {
                char* signal_start = strstr(buffer, "=") + 1;
                char* signal_end = strstr(signal_start, " ");
                int signal_strength;
                sscanf(signal_start, "%d", &signal_strength);
                new_network.signal_strength = signal_strength;
                
                // Check if network is already in list
                bool duplicate = false;
                for (int i = 0; i < num_networks; i++) {
                    if (is_same_network(networks[i], new_network)) {
                        duplicate = true;
                        break;
                    }
                }
                
                // Add network to list if it is not a duplicate
                if (!duplicate) {
                    networks[num_networks] = new_network;
                    num_networks++;
                    network_found = true;
                }
            }
        }
        
        pclose(fp);
        
        // Clear terminal and show networks if any were found
        printf("\033[2J\033[1;1H");
        if (network_found) {
            printf("Wireless Networks Found:\n");
            for (int i = 0; i < num_networks; i++) {
                print_network(networks[i]);
                printf("------------------------------\n");
            }
        } else {
            printf("No wireless networks found\n");
        }
        
        sleep(SCAN_INTERVAL);
    }
}

int main() {
    pthread_t scanner_thread;
    pthread_create(&scanner_thread, NULL, scan_networks, NULL);
    
    pthread_join(scanner_thread, NULL);
    
    return 0;
}