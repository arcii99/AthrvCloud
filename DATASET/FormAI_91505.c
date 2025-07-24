//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    int n, k;
    float x[4] = {1, 2, 3, 4};
    float y[4] = {3, 5, 7, 9};
    float z[4] = {0, 0, 0, 0};

    printf("Original signal: \n");
    for(int i = 0; i < 4; i++)
        printf("x[%d] = %.2f, y[%d] = %.2f\n", i, x[i], i, y[i]);

    for(k = 0; k < 4; k++)
    {
        float sum = 0;
        for(n = 0; n < 4; n++)
        {
            float phase = (-2 * PI * k * n) / 4;
            sum += x[n] * cos(phase) + y[n] * sin(phase);
        }
        z[k] = sum / 4;
    }

    printf("Processed signal: \n");
    for(int i = 0; i < 4; i++)
        printf("z[%d] = %.2f\n", i, z[i]);

    return 0;
}