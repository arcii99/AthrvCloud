//FormAI DATASET v1.0 Category: Digital signal processing ; Style: secure
#include <stdio.h>

// Define the size of the array that will hold the signal samples
#define SIGNAL_SIZE 10

// Function for calculating the average of a signal
double calculate_average(double signal[]) {
    double sum = 0.0;
    int i;
    for (i = 0; i < SIGNAL_SIZE; i++) {
        sum += signal[i];
    }
    return sum / SIGNAL_SIZE;
}

// Function for applying a moving average filter to the signal
void apply_moving_average(double signal[], double filtered_signal[]) {
    int i;
    for (i = 0; i < SIGNAL_SIZE; i++) {
        if (i == 0) {
            // If the sample is first, average it with the next two samples
            filtered_signal[i] = (signal[i] + signal[i+1] + signal[i+2]) / 3.0;
        } else if (i == SIGNAL_SIZE-1) {
            // If the sample is last, average it with the previous two samples
            filtered_signal[i] = (signal[i] + signal[i-1] + signal[i-2]) / 3.0;
        } else {
            // Otherwise, average the sample with the two adjacent samples
            filtered_signal[i] = (signal[i-1] + signal[i] + signal[i+1]) / 3.0;
        }
    }
}

int main() {

    // Define and initialize the signal array
    double signal[SIGNAL_SIZE] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.1, 10.0};

    // Calculate the average of the signal
    double signal_average = calculate_average(signal);
    printf("The average of the signal is %f\n", signal_average);

    // Apply a moving average filter to the signal
    double filtered_signal[SIGNAL_SIZE];
    apply_moving_average(signal, filtered_signal);

    // Calculate the average of the filtered signal
    double filtered_signal_average = calculate_average(filtered_signal);
    printf("The average of the filtered signal is %f\n", filtered_signal_average);

    return 0;
}