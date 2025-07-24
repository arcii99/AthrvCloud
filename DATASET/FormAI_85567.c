//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int signal_strength;
    srand(time(NULL)); //initialize random number generator seed based on current time

    //simulating Wi-Fi signal strength values
    signal_strength = rand() % 101; //generating values from 0 to 100

    printf("Wi-Fi Signal Strength: %d%%\n", signal_strength);

    return 0;
}