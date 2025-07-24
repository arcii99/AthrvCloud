//FormAI DATASET v1.0 Category: Digital signal processing ; Style: complex
#include<stdio.h>
#include<math.h>

#define SIZE 16          // Size of the input sequence
#define PI 3.14159265359 // Value of PI

void fft(double *real, double *imag, int n){

    int i,m,j,k;

    double tempr,tempi,theta,xr = 0,x1,x2,x3,x4,x5,x6,x7,x8;

    int f1,f2,f3,f4,f5,f6,f7,f8;

    m = log((double)n) / log(2.0);

    for(i = 0;i < n;i++){

        j = 0;

        for(k = 0;k < m;k++){
          
            j <<= 1;
      
            if(i & (1<<k)) j++;

        }

        if(j < i){

            tempr = real[j];
            real[j] = real[i];
            real[i] = tempr;

            tempi = imag[j];
            imag[j] = imag[i];
            imag[i] = tempi;

        }

    }

    for(i = 0;i < m;i++){

        theta = -(2*PI/(1<<i));

        xr = 1;
        tempi = sin(theta);
        tempr = cos(theta);

        x1 = tempr;
        x2 = tempi;
        x3 = tempr*tempr - tempi*tempi;
        x4 = 2*tempr*tempi;
        x5 = x3*tempr - x4*tempi;
        x6 = x3*tempi + x4*tempr;
        x7 = x3*x3 - x4*x4;
        x8 = 2*x3*x4;

        for(m = 0;m < (1<<i);m++){

            f1 = m*(1 << (8 - i));
            f2 = f1 + (1 << (7 - i));
            f3 = f2 + (1 << (7 - i));
            f4 = f3 + (1 << (7 - i));
            f5 = f4 + (1 << (7 - i));
            f6 = f5 + (1 << (7 - i));
            f7 = f6 + (1 << (7 - i));
            f8 = f7 + (1 << (7 - i));

            tempr = xr*real[f2] - xr*imag[f3];
            tempi = xr*real[f3] + xr*imag[f2];

            real[f2] = real[f1] - tempr;
            imag[f2] = imag[f1] - tempi;
            real[f3] = real[f1] + tempr;
            imag[f3] = imag[f1] + tempi;

            tempr = x5*real[f6] - x6*imag[f7];
            tempi = x6*real[f6] + x5*imag[f7];

            real[f6] = real[f4] - tempr;
            imag[f6] = imag[f4] - tempi;
            real[f7] = real[f4] + tempr;
            imag[f7] = imag[f4] + tempi;

            tempr = x7*real[f8] - x8*imag[f5];
            tempi = x8*real[f8] + x7*imag[f5];

            real[f8] = real[f1] - tempr;
            imag[f8] = imag[f1] - tempi;
            real[f5] = real[f1] + tempr;
            imag[f5] = imag[f1] + tempi;

            xr = xr*x1 - tempi*x2;
            x2 = xr*x2 + x1*tempi;
            x1 = xr*x1 - tempi*x2;

        }

    }

    k = 16/n;

    for(i = 0;i < n;i++){

        real[i] *= k;
        imag[i] *= k;

    }

}

int main(){

    double inputReal[SIZE];
    double inputImag[SIZE];

    // Initializing the input sequence
    for(int i = 0;i < SIZE;i++){
        inputReal[i] = sin(2*M_PI*1000*i);
        inputImag[i] = 0;
    }

    // Calling the FFT function
    fft(inputReal, inputImag, SIZE);

    // Printing the frequency domain representation of the signal
    for(int i = 0;i < SIZE;i++){
        printf("%lf + %lfj\n", inputReal[i], inputImag[i]);
    }

    return 0;

}