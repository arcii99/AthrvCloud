//FormAI DATASET v1.0 Category: Audio processing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void delaycb (short *delayline, int len, short *out, short input, float gain, int delaylen) {
    int i;
    int dly = (int)(delaylen + (delaylen * sin(2 * PI * 0.02))); // added vibrato
    int frac_dly = dly - (int)dly;
    delayline[len-1] = input;
    for (i = len-2; i >= 0; i--) { // moving the values inside delay buffer
        delayline[i+1] = ((1-frac_dly) * delayline[i]) + (frac_dly * delayline[i+1]);
    }
    *out = delayline[len-1] * gain;
}

int main() {
    short input, output;
    float gain = 0.8;
    int delaylen = 22050;
    short* delayline = (short *) calloc(delaylen+1, sizeof(short)); //delay buffer
    
    // reading input audio sample and writing processed output 
    while (fread(&input, sizeof(short), 1, stdin)) {
        delaycb(delayline, delaylen+1, &output, input, gain, delaylen);
        fwrite(&output, sizeof(short), 1, stdout);
    }
    free(delayline);
    return 0;
}