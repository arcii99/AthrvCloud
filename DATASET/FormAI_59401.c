//FormAI DATASET v1.0 Category: Digital signal processing ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846

int main(){

    int n, i, j;
    float xn[50], xk[50], real[50], imag[50], mag[50], phase[50];

    printf("\n==========================================\n");
    printf("  C Digital Signal Processing Example Program  \n");
    printf("==========================================\n\n");
    printf("Enter the number of samples (n): ");
    scanf("%d", &n);

    printf("\nEnter the values of x(n):\n");

    for(i=0; i<n; i++){
        printf("x[%d] = ", i);
        scanf("%f", &xn[i]);
    }

    printf("\n-------------------------\n");
    printf("|     X(k)     |     Magnitude   |       Phase    |\n");
    printf("-------------------------\n");

    for(i=0; i<n; i++){

        real[i] = 0.0;
        imag[i] = 0.0;

        for(j=0; j<n; j++){
            real[i] += xn[j] * cos((2 * PI * i * j) / n);
            imag[i] -= xn[j] * sin((2 * PI * i * j) / n);
        }

        xk[i] = sqrt(pow(real[i], 2) + pow(imag[i], 2));
        mag[i] = 20 * log10(xk[i] / n);
        phase[i] = atan2(imag[i], real[i]);

        printf("|    X[%2d]   |      %5.2f       |    %5.2f      |\n", i, mag[i], (phase[i] * 180 / PI));

    }

    printf("-------------------------\n");

    return 0;
}