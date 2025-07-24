//FormAI DATASET v1.0 Category: Digital signal processing ; Style: systematic
/* Example program for low-pass filter implementation using digital signal processing

A simple low-pass filter is used to filter out high frequency components from a signal. 
This can be achieved by digital signal processing in microcontroller-based systems. 
This program applies the low-pass filter on an input digital signal to achieve the desired output.

*/

#include <stdio.h>
#include <stdlib.h>

#define SIGNAL_LENGTH 20 // length of input signal
#define ALPHA 0.5 // filter coefficient

int main()
{
    int input_signal[SIGNAL_LENGTH] = {2, 4, 5, 7, 9, 10, 12, 15, 16, 20, 18, 15, 12, 10, 8, 6, 4, 3, 2, 1};
    int output_signal[SIGNAL_LENGTH] = {0}; // initialize output signal

    // Apply the low-pass filter to the input signal
    for(int i=1; i<SIGNAL_LENGTH; i++)
    {
        output_signal[i] = ALPHA*input_signal[i] + (1-ALPHA)*output_signal[i-1];
    }

    // Print the input and output signals
    printf("Input Signal: ");
    for(int i=0; i<SIGNAL_LENGTH; i++)
    {
        printf("%d ", input_signal[i]);
    }
    printf("\n");

    printf("Output Signal: ");
    for(int i=0; i<SIGNAL_LENGTH; i++)
    {
        printf("%d ", output_signal[i]);
    }
    printf("\n");

    return 0; // end of program
}