//FormAI DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h>

// paranoia-level function for filtering signals
void paranoid_filter_signal(float signal[], int length) {
    float filtered_signal[length];

    // apply paranoid-level filtering algorithm
    for (int i = 0; i < length; i++) {
        float factor = i * 0.01; // paranoid-level factor
        filtered_signal[i] = (signal[i] * factor) + (signal[i-1] * (1 - factor));
        if (i >= 5) {
            filtered_signal[i] -= (signal[i-5] * 0.1);
        }
        if (i >= 10) {
            filtered_signal[i] += (signal[i-10] * 0.15);
        }
        if (i >= 15) {
            filtered_signal[i] -= (signal[i-15] * 0.2);
        }
    }

    // print filtered signal
    printf("Filtered Signal:\n");
    for (int j = 0; j < length; j++) {
        printf("%f\n", filtered_signal[j]);
    }
}

int main() {
    // paranoid-level signal processing example
    printf("Paranoid-level Signal Processing Example:\n");

    // generate signal
    float signal[10] = {1.2, 3.7, 2.1, 4.9, 6.3, 4.5, 2.5, 1.0, 0.2, -1.7};

    // print original signal
    printf("Original Signal:\n");
    for (int i = 0; i < 10; i++) {
        printf("%f\n", signal[i]);
    }

    // apply paranoid-level filtering
    paranoid_filter_signal(signal, 10);

    return 0;
}