//FormAI DATASET v1.0 Category: Error handling ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function prototype
double compute_sqrt(double x);

int main() {
    double num, result;
    printf("Enter a positive number: ");
    scanf("%lf", &num);

    if(num < 0) {
        printf("Error: Cannot compute square root of a negative number!\n");
        exit(0);
    }

    result = compute_sqrt(num);
    printf("The square root of %.2lf is %.2lf\n", num, result);

    return 0;
}

double compute_sqrt(double x) {
    if(x < 0) {
        printf("Error: Cannot compute square root of a negative number!\n");
        exit(0);
    }
    return sqrt(x);
}