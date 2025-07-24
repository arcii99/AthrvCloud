//FormAI DATASET v1.0 Category: Computer Biology ; Style: single-threaded
#include <stdio.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int n; // Number of iterations
    double r, p, k, lambda; // Biological parameters

    printf("Enter the number of iterations: ");
    scanf("%d", &n);
    printf("Enter the reproduction rate (r): ");
    scanf("%lf", &r);
    printf("Enter the proportion of the population that survives (p): ");
    scanf("%lf", &p);
    printf("Enter the carrying capacity (k): ");
    scanf("%lf", &k);
    printf("Enter the birth rate (lambda): ");
    scanf("%lf", &lambda);

    int i;
    double S[n+1], I[n+1], R[n+1]; // Arrays to store the population values

    S[0] = 0.9*k; // Initial susceptible population
    I[0] = 0.1*k; // Initial infected population
    R[0] = 0; // Initial recovered population

    for (i = 1; i <= n; i++) {
        // Calculate the next population values using the Lotka-Volterra equations
        S[i] = p*S[i-1] - lambda*S[i-1]/k*I[i-1];
        I[i] = r*lambda/k*S[i-1]*I[i-1]/p - lambda*I[i-1]/k*I[i-1];
        R[i] = lambda*I[i-1]/k*I[i-1];

        // Ensure that the population values do not exceed the carrying capacity
        if (S[i] > k) {
            S[i] = k;
        }
        if (I[i] > k) {
            I[i] = k;
        }
        if (R[i] > k) {
            R[i] = k;
        }
    }

    // Calculate the total population at each iteration
    double N[n+1];
    for (i = 0; i <= n; i++) {
        N[i] = S[i] + I[i] + R[i];
    }

    // Calculate the total number of infections over the course of the simulation
    double total_infections = 0;
    for (i = 0; i < n; i++) {
        total_infections += (I[i+1] - I[i]);
    }

    // Calculate the number of possible combinations of infected individuals
    double combinations = factorial((int)I[n]) / factorial(2) / factorial((int)I[n]-2);

    // Print the results
    printf("Final susceptible population: %.2lf\n", S[n]);
    printf("Final infected population: %.2lf\n", I[n]);
    printf("Final recovered population: %.2lf\n", R[n]);
    printf("Total population at end: %.2lf\n", N[n]);
    printf("Total number of infections: %.2lf\n", total_infections);
    printf("Number of possible combinations of infected individuals: %.2lf\n", combinations);

    return 0;
}