//FormAI DATASET v1.0 Category: Digital signal processing ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265359 //define pi

int main()
{
    int i, N = 16;  //set the value of N

    float x[N], y[N]; //initialize two float arrays x and y

    //initialize the input signal x as a sine wave
    for (i = 0; i < N; i++)
    {
        x[i] = sin(2 * PI * i / N);
    }

    //printing the input signal x
    printf("Input sequence x[n]:\n");
    for (i = 0; i < N; i++)
    {
        printf("%f ", x[i]);
    }

    //applying the Discrete Fourier Transform
    for (i = 0; i < N; i++)
    {
        float real = 0, img = 0;
        for (int j = 0; j < N; j++)
        {
            real += x[j] * cos(2 * PI * i * j / N);
            img -= x[j] * sin(2 * PI * i * j / N);
        }
        y[i] = sqrt(real * real + img * img); //calculating magnitude of the complex number
    }

    //printing the transformed sequence y
    printf("\n\nTransformed sequence y[n]:\n");
    for (i = 0; i < N; i++)
    {
        printf("%f ", y[i]);
    }

    return 0; //successful execution of the program
}