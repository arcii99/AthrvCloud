//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>

int main() {
    // Define variables
    int n1, n2, gcd, lcm, i;

    // Get input from user
    printf("Enter two positive integers: ");
    scanf("%d %d", &n1, &n2);

    // Find the GCD
    for(i=1; i <= n1 && i <= n2; i++) {
        if(n1%i==0 && n2%i==0) {
            gcd = i;
        }
    }

    // Find the LCM
    lcm = (n1*n2) / gcd;

    // Print the results
    printf("The GCD of %d and %d is %d\n", n1, n2, gcd);
    printf("The LCM of %d and %d is %d", n1, n2, lcm);

    return 0;
}