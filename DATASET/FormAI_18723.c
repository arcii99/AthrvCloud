//FormAI DATASET v1.0 Category: Funny ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double randn(double mu, double sigma) {
    // Generate random number from a normal distribution
    static int haveval = 0;
    static double val;
    double u, v, x, y, q;
    if (haveval) {
        haveval = 0;
        return mu + sigma * val;
    }
    do {
        u = (double) rand() / RAND_MAX;
        v = (double) rand() / RAND_MAX;
        x = sqrt(-2. * log(u));
        y = 2 * M_PI * v;
        q = x * sin(y);
    } while (q > 1/2. || q < -1/2.);
    haveval = 1;
    val = q;
    return mu + sigma * x * cos(y);
}

int main() {
    // Set up parameters for generating random numbers
    srand(time(NULL));
    double mu = 50.0;
    double sigma = 10.0;
    int n = 10000;
    int bins = 10;
    int freq[bins];
    for (int i = 0; i < bins; i++) {
        freq[i] = 0;
    }
    
    // Generate and count random numbers
    for (int i = 0; i < n; i++) {
        double num = randn(mu, sigma);
        int bin = floor((num - mu)/sigma * sqrt(n) + bins/2);
        if (bin >= 0 && bin < bins) {
            freq[bin]++;
        }
    }
    
    // Print histogram of random numbers
    for (int i = 0; i < bins; i++) {
        printf("%4.1f - %4.1f | ", mu + (i-bins/2.)*sigma/sqrt(n), mu + (i-bins/2.+1.)*sigma/sqrt(n));
        int stars = freq[i] * 50 / n;
        for (int j = 0; j < stars; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}