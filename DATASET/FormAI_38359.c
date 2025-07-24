//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIGNAL 100
#define MIN_SIGNAL 0
#define THRESHOLD 50

int signal_strength(int x, int y) {
    double distance = sqrt(pow(x, 2) + pow(y, 2));
    int signal = MAX_SIGNAL - (int)(distance / 10) * 10;
    return (signal < MIN_SIGNAL) ? MIN_SIGNAL : signal;
}

int main() {
    int x, y, signal;
    printf("Enter the x-coordinate: ");
    scanf("%d", &x);
    printf("Enter the y-coordinate: ");
    scanf("%d", &y);
    signal = signal_strength(x, y);
    printf("The Wi-Fi signal strength at (%d, %d) is %d.\n", x, y, signal);
    if(signal >= THRESHOLD) {
        printf("Signal strength above threshold.\n");
    } else {
        printf("Signal strength below threshold.\n");
    }
    return 0;
}