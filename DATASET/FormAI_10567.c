//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LENGTH 32

typedef struct access_point {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} access_point_t;

int main() {
    int num_access_points;
    printf("Enter the number of access points: ");
    scanf("%d", &num_access_points);

    access_point_t *access_points = (access_point_t*) malloc(num_access_points * sizeof(access_point_t));
    if (access_points == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        return 1;
    }

    for (int i = 0; i < num_access_points; i++) {
        printf("Enter the SSID of access point %d: ", i+1);
        scanf("%s", access_points[i].ssid);

        printf("Enter the signal strength of access point %d: ", i+1);
        scanf("%d", &access_points[i].signal_strength);
    }

    printf("\nResults:\n");
    printf("%-15s %-10s\n", "SSID", "Strength");
    for (int i = 0; i < num_access_points; i++) {
        printf("%-15s %-10d\n", access_points[i].ssid, access_points[i].signal_strength);
    }

    free(access_points);

    return 0;
}