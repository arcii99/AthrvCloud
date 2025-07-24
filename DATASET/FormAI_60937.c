//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// structure for holding data of each access point
struct access_point {
    char name[20];
    int signal_strength;
};

// function to generate a random signal strength value between -100 and 0
int random_signal_strength() {
    return (-100 + (rand() % 101));
}

// function to print the data of each access point
void print_access_point(struct access_point* ap) {
    printf("Name: %s\tSignal Strength: %d dBm\n", ap->name, ap->signal_strength);
}

int main() {

    // seed the random number generator
    srand(time(NULL));

    // create an array of access points
    struct access_point access_points[5];

    // add data for each access point
    strcpy(access_points[0].name, "AP1");
    access_points[0].signal_strength = random_signal_strength();

    strcpy(access_points[1].name, "AP2");
    access_points[1].signal_strength = random_signal_strength();

    strcpy(access_points[2].name, "AP3");
    access_points[2].signal_strength = random_signal_strength();

    strcpy(access_points[3].name, "AP4");
    access_points[3].signal_strength = random_signal_strength();

    strcpy(access_points[4].name, "AP5");
    access_points[4].signal_strength = random_signal_strength();

    // print the data for each access point
    printf("Access Point Data:\n");
    for (int i = 0; i < 5; i++) {
        print_access_point(&access_points[i]);
    }

    // determine the strongest signal strength and print the result
    int strongest_signal_strength = -100;
    for (int i = 0; i < 5; i++) {
        if (access_points[i].signal_strength > strongest_signal_strength) {
            strongest_signal_strength = access_points[i].signal_strength;
        }
    }
    printf("Strongest Signal Strength: %d dBm\n", strongest_signal_strength);

    // determine the average signal strength and print the result
    int sum_signal_strengths = 0;
    for (int i = 0; i < 5; i++) {
        sum_signal_strengths += access_points[i].signal_strength;
    }
    float avg_signal_strength = (float)sum_signal_strengths / 5;
    printf("Average Signal Strength: %.2f dBm\n", avg_signal_strength);

    return 0;
}