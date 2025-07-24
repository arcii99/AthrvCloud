//FormAI DATASET v1.0 Category: Audio processing ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Recursive function to Apply Echo Effect on Audio
void echo(float *buffer, int bufferSize, int delayInMs, float decay)
{
    //Compute delay in number of samples
    int delayInSamples = (int) ((float)delayInMs * 44.1); //Sampling rate is 44.1 kHz

    //Base case: delay in samples is less than 1, no echo effect is applied
    if(delayInSamples < 1){
        return;
    }

    //Recursive case: compute the echo buffer and add it to the input buffer
    int i;
    for(i=delayInSamples;i<bufferSize;i++){
        buffer[i] += buffer[i - delayInSamples] * decay;
    }
  
    //Recursively call the function by reducing the delay time by half
    echo(buffer, bufferSize, delayInMs/2, decay);
}

int main(){

    //Initialize an input buffer with random values between -1 and 1
    float buffer[10000];
    int i;
    for(i=0;i<10000;i++){
        buffer[i] = ((float)rand()/(float)(RAND_MAX)) * 2.0 - 1.0;
    }

    //Apply echo effect on the input buffer recursively
    echo(buffer, 10000, 50, 0.5);
  
    //Print the output buffer
    for(i=0;i<10000;i++){
        printf("%f\n", buffer[i]);
    }

    return 0;
}