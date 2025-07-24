//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int signal_strength[10];
    int i, j, temp;
    srand(time(NULL));
    for (i = 0; i < 10; i++) {
        signal_strength[i] = rand() % 100;
    }

    printf("Welcome to the Wi-Fi Signal Strength Analyzer\n\n");
    for (i = 0; i < 10; i++) {
        printf("Signal strength of the router %d is: %d\n", i+1, signal_strength[i]);
    }

    // Bubble sort
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9-i; j++) {
            if (signal_strength[j] < signal_strength[j+1]) {
                temp = signal_strength[j];
                signal_strength[j] = signal_strength[j+1];
                signal_strength[j+1] = temp;
            }
        }
    }

    printf("\nSorted signal strength:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", signal_strength[i]);
    }

    int max_signal_strength = signal_strength[0];
    int max_signal_index = 0;
    for (i = 1; i < 10; i++) {
        if (signal_strength[i] > max_signal_strength) {
            max_signal_strength = signal_strength[i];
            max_signal_index = i;
        }
    }

    printf("\n\nThe strongest Wi-Fi signal is from router %d with a signal strength of %d\n", max_signal_index+1, max_signal_strength);
    printf("All the other routers have a signal strength of less than %d\n", max_signal_strength);

    return 0;
}