//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ken Thompson
#include <stdio.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

typedef struct {
    int signal_strength;
    char* name;
} AccessPoint;

int main() {
    AccessPoint access_points[5] = {
        {75, "RouterA"},
        {85, "RouterB"},
        {60, "RouterC"},
        {90, "RouterD"},
        {50, "RouterE"}
    };

    printf("Wi-Fi Signal Strength Analyzer:\n\n");

    for (int i = 0; i < 5; i++) {
        printf("%s has a signal strength of %d\n", access_points[i].name, access_points[i].signal_strength);
    }

    int average_signal_strength = 0;
    int lowest_signal_strength = MAX_SIGNAL_STRENGTH;
    int highest_signal_strength = MIN_SIGNAL_STRENGTH;

    for (int i = 0; i < 5; i++) {
        average_signal_strength += access_points[i].signal_strength;

        if (access_points[i].signal_strength < lowest_signal_strength) {
            lowest_signal_strength = access_points[i].signal_strength;
        }

        if (access_points[i].signal_strength > highest_signal_strength) {
            highest_signal_strength = access_points[i].signal_strength;
        }
    }

    average_signal_strength /= 5;

    printf("\nAverage signal strength: %d\n", average_signal_strength);
    printf("Lowest signal strength: %d\n", lowest_signal_strength);
    printf("Highest signal strength: %d\n", highest_signal_strength);

    return 0;
}