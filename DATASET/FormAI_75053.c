//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cryptic
#include<stdio.h>
#include<math.h>

int main()
{
    int n, i, j;
    float x[50], y[50], r[50], area, temp, k, s, l, a, b, c, p;

    printf("Enter the number of circles: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the coordinates and radius of circle %d: ", i + 1);
        scanf("%f %f %f", &x[i], &y[i], &r[i]);

        for (j = i; j > 0; j--)
        {
            if (r[j] > r[j - 1])
            {
                temp = r[j];
                r[j] = r[j - 1];
                r[j - 1] = temp;

                temp = x[j];
                x[j] = x[j - 1];
                x[j - 1] = temp;

                temp = y[j];
                y[j] = y[j - 1];
                y[j - 1] = temp;
            }
        }
    }

    area = 0;

    for (i = 0; i < n; i++)
    {
        k = sqrt(pow((x[i] - x[(i + 1) % n]), 2) + pow((y[i] - y[(i + 1) % n]), 2));
        s = (r[i] + r[(i + 1) % n] + k) / 2;
        l = sqrt(s * (s - r[i]) * (s - r[(i + 1) % n]) * (s - k));
        a = acos((pow(r[i], 2) - pow(r[(i + 1) % n], 2) + pow(k, 2)) / (2 * r[i] * k));
        b = acos((pow(r[(i + 1) % n], 2) - pow(r[i], 2) + pow(k, 2)) / (2 * r[(i + 1) % n] * k));
        c = acos((pow(r[i], 2) + pow(r[(i + 1) % n], 2) - pow(k, 2)) / (2 * r[i] * r[(i + 1) % n]));

        p = (r[i] + r[(i + 1) % n] + k) / 2;

        area += l + r[i] * r[i] * (b - sin(b)) / 2 + r[(i + 1) % n] * r[(i + 1) % n] * (a - sin(a)) / 2 + ((r[i] * r[i] * r[i] * c) + (r[(i + 1) % n] * r[(i + 1) % n] * r[(i + 1) % n] * c)) / 3;
    }

    printf("The total area is %f\n", area);

    return 0;
}