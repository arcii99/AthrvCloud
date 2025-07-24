//FormAI DATASET v1.0 Category: Digital signal processing ; Style: unmistakable
#include<stdio.h>
#include<math.h>

//Function to calculate moving average
void moving_average(float samples[], float output[], int num_samples, int window_size) {
    float sum = 0.0;
    int i, j;
    for(i=0; i<num_samples-window_size+1; i++) {
        //Calculating sum of samples within current window
        for(j=0; j<window_size; j++) {
            sum += samples[i+j];
        }
        //Calculating average of samples within current window
        output[i] = sum/window_size;
        sum = 0;
    }
}

int main() {
    int num_samples = 10;
    float samples[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    int window_size = 3;

    float output[num_samples-window_size+1];
    moving_average(samples, output, num_samples, window_size);

    printf("Input Signal:\n");
    int i;
    for(i=0; i<num_samples; i++) {
        printf("%f ", samples[i]);
    }

    printf("\n\nOutput Signal (Moving Average):\n");
    for(i=0; i<num_samples-window_size+1; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    return 0;
}