//FormAI DATASET v1.0 Category: Digital signal processing ; Style: relaxed
#include <stdio.h>
#include <math.h>

#define FS 44100    //sampling frequency
#define FREQ 1000   //frequency of sine wave
#define AMP 0.5     //amplitude of sine wave
#define PI 3.14159265358979323846

int main()
{
    float x, y, phase = 0;
    int i;

    for(i=0; i<FS; i++)
    {
        x = AMP * sin(2 * PI * FREQ * i / FS + phase);
        y = x * sin(2 * PI * (FREQ + 100) * i / FS);    //modulate with a higher frequency sine wave
        printf("%f\n", y);  //output the modulated signal
    }

    return 0;
}