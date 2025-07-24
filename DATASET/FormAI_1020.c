//FormAI DATASET v1.0 Category: Digital signal processing ; Style: light-weight
#include <stdio.h>

// function to perform convolution of two signals
void convolution(int signal1[], int signal2[], int result[], int len1, int len2) {
    int len_res = len1 + len2 - 1;  // length of result signal
    int temp;

    // initialize result signal to 0
    for (int i = 0; i < len_res; i++) {
        result[i] = 0;
    }

    // perform convolution
    for (int i = 0; i < len_res; i++) {
        temp = 0;

        for (int j = 0; j <= i; j++) {
            if (j < len1 && i-j < len2) {
                temp += signal1[j] * signal2[i-j];
            }
        }

        result[i] = temp;
    }
}

int main() {
    int sig1[] = {1, 2, 3};  // input signal 1
    int sig2[] = {4, 5, 6};  // input signal 2
    int result[5];  // result signal

    // perform convolution of input signals
    convolution(sig1, sig2, result, 3, 3);

    // print input and result signals
    printf("Signal 1: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", sig1[i]);
    }
    printf("\n");

    printf("Signal 2: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", sig2[i]);
    }
    printf("\n");

    printf("Result Signal: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}