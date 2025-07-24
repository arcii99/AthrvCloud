//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.1415926535   // Defining the value of pi

int main()
{
    int n;        // Declaring variable for number of samples 
    float xn;     // Declaring variable for Input signal 
    float fc;     // Declaring variable for Cut off frequency
    float ts;     // Declaring variable for Sampling time
    float d = 0.9;// Declaring variable for decay rate
    float y;      // Declaring variable for Output signal
    float alpha;  

    scanf("%d",&n);
    scanf("%f",&xn);
    scanf("%f",&fc);
    scanf("%f",&ts);

    alpha = exp(-2*PI*fc*ts);      // Defining the alpha value to use for the low pass filter  
    y = xn; // Initializing the output signal as the input signal for the first sample 

    printf("Input Signal: %.2f\n", xn);
    printf("Output Signal: %.2f\n", y);

    for(int i=1;i<n;i++){
        scanf("%f",&xn);
        y = (1-alpha)*xn + alpha*y;   // Digital Low Pass Filter Implementation
        y *= d;                       // Decaying the output signal 
        printf("Input Signal: %.2f\n", xn);
        printf("Output Signal: %.2f\n", y);
    }

    return 0;
}