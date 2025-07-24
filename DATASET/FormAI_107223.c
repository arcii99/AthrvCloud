//FormAI DATASET v1.0 Category: Digital signal processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAMPLE_RATE 8000 // 8 kHz sampling rate
#define NUM_SAMPLES 80000 // 10 seconds of audio
#define MAX_AMPLITUDE 32767 // maximum amplitude for 16-bit signed values

int main()
{
   // Generate random noise as input signal
   int input_signal[NUM_SAMPLES];
   srand(time(NULL)); // Seed for random number generation
   for(int i=0; i<NUM_SAMPLES; i++){
       input_signal[i] = (rand() % (2*MAX_AMPLITUDE)) - MAX_AMPLITUDE; // create values between -32767 to 32767
   }

   // Perform low-pass filtering 
   int output_signal[NUM_SAMPLES];
   float cutoff_frequency = 1000; // Hz
   float RC = 1.0 / (2 * 3.14 * cutoff_frequency);
   float alpha = SAMPLE_RATE / (RC + SAMPLE_RATE); // alpha is smoothing constant
   output_signal[0] = input_signal[0];
   for(int i=1; i<NUM_SAMPLES; i++){
       output_signal[i] = alpha * input_signal[i] + (1 - alpha) * output_signal[i-1]; // low pass filter equation
   }

   // Amplify signal to max amplitude
   float max_input_amplitude = 0;
   float max_output_amplitude = 0;
   for(int i=0; i<NUM_SAMPLES; i++){
       if(abs(input_signal[i]) > max_input_amplitude){
           max_input_amplitude = abs(input_signal[i]); // find max amplitude in input signal
       }
       if(abs(output_signal[i]) > max_output_amplitude){
           max_output_amplitude = abs(output_signal[i]); // find max amplitude in output signal
       }
   }
   float amplification_factor = MAX_AMPLITUDE / max_output_amplitude; // calculate amplification factor
   for(int i=0; i<NUM_SAMPLES; i++){
       output_signal[i] *= amplification_factor; // amplify output signal to max amplitude
   }

   // Print out the filtered and amplified signal values
   printf("Input Signal\tOutput Signal\n");
   for(int i=0; i<NUM_SAMPLES; i++){
       printf("%d\t\t%.0f\n", input_signal[i], output_signal[i]);
   }

   return 0;
}