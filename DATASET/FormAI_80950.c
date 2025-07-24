//FormAI DATASET v1.0 Category: Digital signal processing ; Style: funny
#include <stdio.h>

int main() {

    printf("Welcome to the DSP joke corner! \n");
    printf("Here's a funny DSP program for you today! \n");

    int i;

    int x[10] = {1, 2, 3, 4, 5, 6 ,7, 8, 9, 10};
    int y[10] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int n = 10;

    int convolve = 0;

    for(i = 0; i < n; i++) {
        convolve += x[i] * y[n - i - 1];
    }

    printf("The hilarious convolution of x and y is %d! \n", convolve);

    printf("Why did the DSP engineer refuse to help out with the company barbecue? \n");
    printf("Because they didn't want to be caught up in FIR-ing up the grill! \n");

    printf("Thank you for joining us at the DSP joke corner! Come back soon for more laughs! \n");

    return 0;
}