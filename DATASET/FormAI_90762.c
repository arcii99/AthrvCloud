//FormAI DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include<stdio.h>
#define PI 3.14159265358979
#define N 8

void FFT(int dir,int m,double *x,double *y){
   long i,j,k,n1,n2,a;
   double c,s,t1,t2;

   // Bit-reverse
   j = 0;
   n2 = N / 2;
   for (i = 1; i < N - 1; i++) {
      n1 = n2;
      while (j >= n1) {
         j = j - n1;
         n1 = n1 / 2;
      }
      j = j + n1;

      if (i < j) {
         t1 = x[i];
         x[i] = x[j];
         x[j] = t1;
         t1 = y[i];
         y[i] = y[j];
         y[j] = t1;
      }
   }

   // FFT
   n1 = 0;
   n2 = 1;

   for (i = 0; i < m; i++) {
      n1 = n2;
      n2 = n2 + n2;
      a = 0;

      for (j = 0; j < n1; j++) {
         c = cos(a * PI / N);
         s = dir * sin(a * PI / N);
         a += 1 << (m - i - 1);

         for (k = j; k < N; k = k + n2) {
            t1 = c * x[k + n1] - s * y[k + n1];
            t2 = s * x[k + n1] + c * y[k + n1];
            x[k + n1] = x[k] - t1;
            y[k + n1] = y[k] - t2;
            x[k] = x[k] + t1;
            y[k] = y[k] + t2;
         }
      }
   }
}

int main() {
  int i;
  double x[N] = {1,2,3,4,5,6,7,8};
  double y[N] = {0};

  // Display original signal
  printf("Original Signal:\n");
  for(i=0;i<N;i++){
      printf("%lf ",x[i]);
  }
  printf("\n");
  
  // Take FFT of signal
  FFT(1,3,x,y);

  // Display frequency domain representation of signal
  printf("Frequency Domain Representation:\n");
  for(i=0;i<N;i++){
      printf("%lf + %lfi\n",x[i],y[i]);
  }
  
  // Take inverse FFT of signal
  FFT(-1,3,x,y);
  
  // Display recovered signal
  printf("Recovered Signal:\n");
  for(i=0;i<N;i++){
      x[i] /= N;
      printf("%lf ",x[i]);
  }
  printf("\n");
  
  return 0;
}