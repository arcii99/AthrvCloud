//FormAI DATASET v1.0 Category: Audio processing ; Style: scientific
#include <stdio.h>    
#include <stdlib.h>   
#include <math.h>     
#include <stdint.h>   
  
#define SAMPLE_RATE 44100    // Number of samples per second  
#define PI 3.14159265359     
  
// Calculates the frequency in Hertz of a given midi note number  
float midiToFreq(uint8_t note){  
  return 440.0 * pow(2, (note - 69) / 12.0);  
}  
  
// Calculates the value of a sine wave at a given time  
float sineWave(float time, float frequency){  
  return sin(2.0 * PI * frequency * time);  
}  
  
// Adds a vibrato effect to a given signal  
float addVibrato(float signal, float time, float vibratoRate, float vibratoDepth){  
  float vibratoFreq = sin(2.0 * PI * vibratoRate * time);  
  return signal * (1.0 + vibratoDepth * vibratoFreq);  
}  
  
int main(){  
  // Generate a 4-second long 440hz sine wave with vibrato  
  float seconds = 4.0;  
  uint32_t numSamples = SAMPLE_RATE * seconds;  
   
  float frequency = midiToFreq(69);  
  float timeStep = 1.0 / SAMPLE_RATE;  
   
  float vibratoRate = 4.0;  
  float vibratoDepth = 0.1;  
   
  float signal;  
  for(uint32_t i = 0; i < numSamples; i++){  
    float time = i * timeStep;  
    signal = sineWave(time, frequency);  
    signal = addVibrato(signal, time, vibratoRate, vibratoDepth);  
    printf("%f\n", signal);  
  }  
  
  return 0;  
}