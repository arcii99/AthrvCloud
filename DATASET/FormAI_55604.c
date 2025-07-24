//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void analyze_wifi_strength() {
    int strength = rand() % 100;
    printf("Signal strength: %d\n", strength);
    //analyze signal strength and print results
    if (strength >= 80) {
        printf("Signal strength is very strong\n");
    } else if (strength >= 60) {
        printf("Signal strength is moderately strong\n");
    } else if (strength >= 40) {
        printf("Signal strength is average\n");
    } else {
        printf("Signal strength is weak\n");
    }
}

int main() {
    printf("Analyzing Wi-Fi signal strength...\n");
    sleep(2);
    analyze_wifi_strength();
    return 0;
}