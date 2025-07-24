//FormAI DATASET v1.0 Category: Math exercise ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){
    int a, b, c, d, e, f, g, h, i, j;
    srand(time(NULL));

    // Randomly generate values for variables a-j
    a = rand() % 100; 
    b = rand() % 100;
    c = rand() % 100;
    d = rand() % 100;
    e = rand() % 100;
    f = rand() % 100;
    g = rand() % 100;
    h = rand() % 100;
    i = rand() % 100;
    j = rand() % 100;

    // Find the sum of variables a-j
    int sum = a + b + c + d + e + f + g + h + i + j;

    // Find the mean of variables a-j
    float mean = (float)sum / 10;

    // Find the standard deviation of variables a-j
    float variance = (pow((float)a-mean,2) + pow((float)b-mean,2) + pow((float)c-mean,2) + pow((float)d-mean,2) + pow((float)e-mean,2) + pow((float)f-mean,2) + pow((float)g-mean,2) + pow((float)h-mean,2) + pow((float)i-mean,2) + pow((float)j-mean,2)) / 10;
    float std_deviation = sqrt(variance);

    // Print out the values of variables a-j, the sum, mean, and standard deviation
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
    printf("Value of c: %d\n", c);
    printf("Value of d: %d\n", d);
    printf("Value of e: %d\n", e);
    printf("Value of f: %d\n", f);
    printf("Value of g: %d\n", g);
    printf("Value of h: %d\n", h);
    printf("Value of i: %d\n", i);
    printf("Value of j: %d\n", j);
    printf("Sum of a-j: %d\n", sum);
    printf("Mean of a-j: %.2f\n", mean);
    printf("Standard Deviation of a-j: %.2f\n", std_deviation);

    // Return 0 to indicate successful execution
    return 0;
}