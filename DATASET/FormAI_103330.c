//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_AP 10
#define MAX_LENGTH 50

struct access_point {
    char name[MAX_LENGTH];
    int signal_strength;
};

void generate_access_points(struct access_point *aps) {
    strcpy(aps[0].name, "Linksys");
    aps[0].signal_strength = rand() % 101;

    strcpy(aps[1].name, "Netgear");
    aps[1].signal_strength = rand() % 101;

    strcpy(aps[2].name, "TP-Link");
    aps[2].signal_strength = rand() % 101;

    strcpy(aps[3].name, "Belkin");
    aps[3].signal_strength = rand() % 101;

    strcpy(aps[4].name, "D-Link");
    aps[4].signal_strength = rand() % 101;
}

void print_table_header() {
    printf("| %-10s | %-10s |\n", "Access Point", "Signal Strength");
    printf("|------------|---------------|\n");
}

void print_access_points(struct access_point *aps) {
    for (int i = 0; i < MAX_AP; i++) {
        printf("| %-10s | %-14d |\n", aps[i].name, aps[i].signal_strength);
    }
}

int main() {
    struct access_point access_points[MAX_AP];

    srand(time(0));
    generate_access_points(access_points);

    printf("Wi-Fi Signal Strength Analyzer\n");
    print_table_header();
    print_access_points(access_points);
    return 0;
}