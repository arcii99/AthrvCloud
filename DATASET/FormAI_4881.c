//FormAI DATASET v1.0 Category: Math exercise ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// We will calculate the sum of the first N prime numbers
int main() {

    int N = 50;
    int count = 0;
    int sum = 0;
    int num = 2;

    while (count < N) {
        int is_prime = 1;
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            sum += num;
            count++;
        }
        num++;
    }

    printf("The sum of the first %d prime numbers is %d\n", N, sum);

    // Now, let's calculate the value of pi using the Monte Carlo simulation
    int N_points = 10000000;
    int N_inside = 0;
    double x, y;

    for (int i = 0; i < N_points; i++) {
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        if (sqrt(x * x + y * y) < 1.0) {
            N_inside++;
        }
    }

    double pi = 4.0 * N_inside / N_points;
    printf("The estimated value of pi using the Monte Carlo simulation with %d points is %f\n", N_points, pi);

    return 0;
}