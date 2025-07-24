//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, i, j;
    float *data, mean, sd;

    printf("Enter the number of data points: ");
    scanf("%d", &size);

    data = (float*)malloc(size * sizeof(float));
    if (data == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the data points:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%f", &data[i]);
    }

    mean = 0;
    for (i = 0; i < size; i++)
    {
        mean += data[i];
    }
    mean /= size;

    sd = 0;
    for (i = 0; i < size; i++)
    {
        sd += (data[i] - mean) * (data[i] - mean);
    }
    sd = sqrt(sd / (size - 1));

    printf("Mean: %f\n", mean);
    printf("Standard deviation: %f\n", sd);

    free(data);
    return 0;
}