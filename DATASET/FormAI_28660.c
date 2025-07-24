//FormAI DATASET v1.0 Category: Digital signal processing ; Style: rigorous
#include <stdio.h>

#define N 5

void convolution(int signal[], int filter[], int output[]) {
    for (int i = 0; i < N; i++) {
        output[i] = 0;
        for (int j = 0; j <= i; j++) {
            output[i] += signal[j] * filter[i-j];
        }
    }
}

int main() {
    int signal[] = {1, 2, 3, 4, 5};
    int filter[] = {5, 4, 3, 2, 1};
    int output[N];

    convolution(signal, filter, output);

    printf("Signal: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", signal[i]);
    }

    printf("\nFilter: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", filter[i]);
    }

    printf("\nOutput: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", output[i]);
    }
    
    return 0;
}