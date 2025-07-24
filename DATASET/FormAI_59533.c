//FormAI DATASET v1.0 Category: Scientific ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calculate_euler_number(int n);

int main() {
    int n;
    double e;

    printf("Enter a value for n: ");
    scanf("%d", &n);

    e = calculate_euler_number(n);

    printf("The Euler number for n = %d is: %.15lf\n", n, e);

    return 0;
}

double calculate_euler_number(int n) {
    double e = 0;
    int i;

    for(i = 0; i <= n; i++) {
        e += 1 / pow(2, i) ;
    }

    return e;
}