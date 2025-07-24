//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define MAX_WIFI_SIGNAL_STRENGTH 100

typedef struct wifi_info {
    char *name;
    float strength;
} wifi_info_t;

typedef struct wifi_list {
    size_t size;
    wifi_info_t *list;
} wifi_list_t;

float calculate_distance_from_signal_strength(float signal_strength) {
    float distance = pow(10, ((-32 - (signal_strength)) / (10 * 2)));
    return distance;
}

void print_wifi_list(wifi_list_t *wifi_list) {
    printf("Available Wi-Fi Networks\n");
    printf("------------------------\n");
    for (size_t i = 0; i < wifi_list->size; i++) {
        wifi_info_t wifi_data = wifi_list->list[i];
        printf("%s : %f meters away\n", wifi_data.name, calculate_distance_from_signal_strength(wifi_data.strength));
    }
}

int main(int argc, char **argv) {

    wifi_info_t wifi_networks[] = {
        {"Wi-Fi Network 1", -50.0},
        {"Wi-Fi Network 2", -60.0},
        {"Wi-Fi Network 3", -70.0},
        {"Wi-Fi Network 4", -80.0},
        {"Wi-Fi Network 5", -90.0}
    };

    wifi_list_t wifi_list;
    wifi_list.size = sizeof(wifi_networks) / sizeof(wifi_info_t);
    wifi_list.list = wifi_networks;

    print_wifi_list(&wifi_list);

    return 0;
}