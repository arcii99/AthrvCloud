//FormAI DATASET v1.0 Category: Audio processing ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

double gaussrand()
{
    static double V1, V2, S;
    static int phase = 0;
    double X;

    if (phase == 0)
    {
        do
        {
            double U1 = (double)rand() / RAND_MAX;
            double U2 = (double)rand() / RAND_MAX;

            V1 = 2 * U1 - 1;
            V2 = 2 * U2 - 1;
            S = V1 * V1 + V2 * V2;
        } while (S >= 1 || S == 0);

        X = V1 * sqrt(-2 * log(S) / S);
    }
    else
    {
        X = V2 * sqrt(-2 * log(S) / S);
    }

    phase = 1 - phase;

    return X;
}

int main()
{
    double f1 = 1000.0, f2 = 1500.0, fm = 2000.0, T = 1.0 / 8000.0;
    double A1 = 0.8, A2 = 0.4;
    double alpha = 0.98, beta = 0.7;
    double x1, x2, x, y;
    double xn, yn;

    FILE *fp;
    fp = fopen("romantic_audio.raw", "wb");

    for (double t = 0; t < 1.0; t += T)
    {
        x1 = A1 * sin(2 * PI * f1 * t);
        x2 = A2 * sin(2 * PI * f2 * t);
        x = x1 + x2;

        xn = alpha * x + (1 - alpha) * xn;
        yn = beta * x + (1 - beta) * yn + gaussrand() * 0.1;

        y = sin(2 * PI * fm * t + 3.14159 * yn / 2);

        short out = (short)(y * 32767.0);
        fwrite(&out, sizeof(out), 1, fp);
    }

    fclose(fp);
    return 0;
}