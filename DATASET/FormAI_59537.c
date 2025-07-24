//FormAI DATASET v1.0 Category: Digital signal processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

int main()
{
    float signal[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    float output[10];
    float omega = 2.0*PI/10.0;
    float cosine = cos(omega);
    float sine = sin(omega);

    float coef_re = 1.0;
    float coef_im = 0.0;

    int i, j;
    for(i=0; i<10; i++)
    {
        output[i] = 0.0;
        for(j=0; j<10; j++)
        {
            output[i] += signal[j] * coef_re;
            float tmp = coef_re;
            coef_re = cosine * coef_re - sine * coef_im;
            coef_im = sine * tmp + cosine * coef_im;
        }
    }

    for(i=0; i<10; i++)
    {
        printf("Output[%d] = %.2f\n", i, output[i]);
    }

    return 0;
}