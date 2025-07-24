//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NETWORKS 100
#define MAX_SSID_LEN 32

struct wifi_network {
    char ssid[MAX_SSID_LEN];
    double x, y; // position on a 2D plane
    double signal_strength; // in dBm
};

// returns the Euclidean distance between two points (x1, y1) and (x2, y2)
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

// prints information about a wifi network
void print_network(struct wifi_network network) {
    printf("SSID: %s\n", network.ssid);
    printf("Position: (%.2f, %.2f)\n", network.x, network.y);
    printf("Signal strength: %.2f dBm\n\n", network.signal_strength);
}

int main() {
    struct wifi_network networks[MAX_NETWORKS];
    int num_networks = 0;
    
    // fake data 
    networks[num_networks++] = (struct wifi_network) { "MyWifi1", 0.0, 0.0, -60.0 };
    networks[num_networks++] = (struct wifi_network) { "MyWifi2", 10.0, 0.0, -70.0 };
    networks[num_networks++] = (struct wifi_network) { "MyWifi3", 0.0, 10.0, -80.0 };
    networks[num_networks++] = (struct wifi_network) { "MyWifi4", 10.0, 10.0, -90.0 };
    
    // input parameters
    double x = 5.0; // my position on the 2D plane
    double y = 5.0;
    
    // print all the networks
    printf("All the wifi networks:\n");
    for (int i=0; i<num_networks; i++) {
        print_network(networks[i]);
    }
    
    // find the nearest network to my position
    double min_distance = INFINITY;
    int nearest_network_index = -1;
    for (int i=0; i<num_networks; i++) {
        double d = distance(x, y, networks[i].x, networks[i].y);
        if (d < min_distance) {
            min_distance = d;
            nearest_network_index = i;
        }
    }
    printf("Nearest wifi network:\n");
    print_network(networks[nearest_network_index]);
    
    // find all networks whose signal strength is above a threshold
    double threshold = -75.0;
    int num_strong_networks = 0;
    struct wifi_network strong_networks[MAX_NETWORKS]; // temporary array
    for (int i=0; i<num_networks; i++) {
        if (networks[i].signal_strength >= threshold) {
            strong_networks[num_strong_networks++] = networks[i];
        }
    }
    printf("Strong wifi networks (signal strength >= -75 dBm):\n");
    for (int i=0; i<num_strong_networks; i++) {
        print_network(strong_networks[i]);
    }
    
    return 0;
}