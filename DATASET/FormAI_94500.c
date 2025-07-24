//FormAI DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator

    int a, b, c, d, e, f, g, h, i, j;
    double avg;

    a = rand() % 20 + 1; // Generate random numbers between 1 and 20
    b = rand() % 20 + 1;
    c = rand() % 20 + 1;
    d = rand() % 20 + 1;
    e = rand() % 20 + 1;
    f = rand() % 20 + 1;
    g = rand() % 20 + 1;
    h = rand() % 20 + 1;
    i = rand() % 20 + 1;
    j = rand() % 20 + 1;

    printf("Welcome to the visionary C Math Exercise program!\n\n");
    printf("Today, we will be working on some advanced statistical analysis.\n\n");

    printf("The following numbers have been randomly generated for you:\n");
    printf("%d %d %d %d %d %d %d %d %d %d\n\n", a, b, c, d, e, f, g, h, i, j);

    avg = (a + b + c + d + e + f + g + h + i + j) / 10.0; // Calculate the average

    printf("The average of these numbers is %.2lf.\n\n", avg);

    printf("Now, let's calculate the standard deviation.\n");

    double sum_of_squares = 0;
    sum_of_squares += (a - avg) * (a - avg);
    sum_of_squares += (b - avg) * (b - avg);
    sum_of_squares += (c - avg) * (c - avg);
    sum_of_squares += (d - avg) * (d - avg);
    sum_of_squares += (e - avg) * (e - avg);
    sum_of_squares += (f - avg) * (f - avg);
    sum_of_squares += (g - avg) * (g - avg);
    sum_of_squares += (h - avg) * (h - avg);
    sum_of_squares += (i - avg) * (i - avg);
    sum_of_squares += (j - avg) * (j - avg);

    double sd = sqrt(sum_of_squares / 10.0); // Calculate the standard deviation

    printf("The standard deviation of these numbers is %.2lf.\n\n", sd);

    printf("Thank you for using the visionary C Math Exercise program!\n");

    return 0;
}