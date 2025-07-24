//FormAI DATASET v1.0 Category: Digital signal processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    float sum = 0, x[20], h[20], y[20];

    printf("Enter the length of the input sequence: ");
    scanf("%d", &n);

    printf("Enter the input sequence:\n");
    for(i=0; i<n; i++)
        scanf("%f", &x[i]);

    printf("Enter the length of the impulse response: ");
    scanf("%d", &n);

    printf("Enter the impulse response:\n");
    for(i=0; i<n; i++)
        scanf("%f", &h[i]);

    /* convolution calculation */
    for(i=0; i<n; i++)
    {
        y[i] = 0;
        for(int j=0; j<=i; j++)
            y[i] += h[j] * x[i-j];
    }

    printf("The output sequence is:\n");
    for(i=0; i<n; i++)
        printf("%0.2f ", y[i]);

    printf("\n\n");

    return 0;
}