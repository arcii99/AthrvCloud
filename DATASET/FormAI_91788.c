//FormAI DATASET v1.0 Category: Digital signal processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
   // Generate a 2 kHz sine wave with sampling frequency 44.1 kHz and duration 2 seconds
   int Fs = 44100;
   int duration = 2;
   float f = 2000.0;
   int N = Fs * duration;
   float t[N], x[N];
   for (int i = 0; i < N; i++) {
       t[i] = (float)i / Fs;
       x[i] = sin(2 * PI * f * t[i]);
   }
   
   // Apply a low-pass filter with cutoff frequency 1 kHz
   float fc = 1000.0;
   float wc = 2 * PI * fc;
   float alpha = wc / (wc + Fs);
   float y[N];
   float y_prev = 0.0;
   for (int i = 0; i < N; i++) {
       y[i] = alpha * x[i] + (1 - alpha) * y_prev;
       y_prev = y[i];
   }
   
   // Compute the FFT of the filtered signal and find the frequency with highest magnitude
   float Xr[N], Xi[N];
   for (int i = 0; i < N; i++) {
       Xr[i] = y[i];
       Xi[i] = 0.0;
   }
   FFT(Xr, Xi, N);
   int k_max = 0;
   float mag_max = 0.0;
   for (int k = 0; k < N/2; k++) {
       float mag = sqrt(Xr[k]*Xr[k] + Xi[k]*Xi[k]);
       if (mag > mag_max) {
           k_max = k;
           mag_max = mag;
       }
   }
   float f_max = (float)k_max * Fs / N;
   
   // Print the frequency with highest magnitude and the filtered signal to a file
   FILE* fp;
   fp = fopen("output.txt", "w");
   fprintf(fp, "Frequency with highest magnitude: %f Hz\n", f_max);
   fprintf(fp, "Time (s)     Input      Output\n");
   for (int i = 0; i < N; i++) {
       fprintf(fp, "%f %f %f\n", t[i], x[i], y[i]);
   }
   fclose(fp);
   
   return 0;
}

void FFT(float* Xr, float* Xi, int N)
{
   if (N == 1) {
       return;
   }
   float Xr_even[N/2], Xi_even[N/2], Xr_odd[N/2], Xi_odd[N/2];
   for (int i = 0; i < N/2; i++) {
       Xr_even[i] = Xr[2*i];
       Xi_even[i] = Xi[2*i];
       Xr_odd[i] = Xr[2*i+1];
       Xi_odd[i] = Xi[2*i+1];
   }
   FFT(Xr_even, Xi_even, N/2);
   FFT(Xr_odd, Xi_odd, N/2);
   for (int k = 0; k < N/2; k++) {
       float angle = -2.0 * PI * k / N;
       float Wk_r = cos(angle);
       float Wk_i = sin(angle);
       float Xr_temp = Xr_odd[k] * Wk_r - Xi_odd[k] * Wk_i;
       float Xi_temp = Xr_odd[k] * Wk_i + Xi_odd[k] * Wk_r;
       Xr[k] = Xr_even[k] + Xr_temp;
       Xi[k] = Xi_even[k] + Xi_temp;
       Xr[k + N/2] = Xr_even[k] - Xr_temp;
       Xi[k + N/2] = Xi_even[k] - Xi_temp;
   }
}