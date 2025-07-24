//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int signal_strengths[10]; // initialize array to hold signal strengths
    srand(time(NULL)); // seed random number generator

    // populate array with random signal strengths between -100 and 0
    for (int i=0; i<10; i++) {
        signal_strengths[i] = rand() % 101 * -1;
    }

    // sort array in ascending order
    for (int i=0; i<9; i++) {
        for (int j=i+1; j<10; j++) {
            if (signal_strengths[i] > signal_strengths[j]) {
                int temp = signal_strengths[i];
                signal_strengths[i] = signal_strengths[j];
                signal_strengths[j] = temp;
            }
        }
    }

    // calculate average signal strength
    int total = 0;
    for (int i=0; i<10; i++) {
        total += signal_strengths[i];
    }
    float average = total / 10.0;

    // print out results
    printf("Wi-Fi Signal Strengths:\n");
    for (int i=0; i<10; i++) {
        printf("%d ", signal_strengths[i]);
    }
    printf("\n\nAverage Signal Strength: %.2f dBm\n", average);

    // determine signal quality based on average signal strength
    if (average >= -60) {
        printf("Signal Quality: Excellent\n");
    } else if (average >= -70) {
        printf("Signal Quality: Good\n");
    } else if (average >= -80) {
        printf("Signal Quality: Fair\n");
    } else if (average >= -90) {
        printf("Signal Quality: Poor\n");
    } else {
        printf("Signal Quality: Very Poor\n");
    }

    return 0;
}