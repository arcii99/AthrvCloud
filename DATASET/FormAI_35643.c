//FormAI DATASET v1.0 Category: Educational ; Style: introspective
#include <stdio.h>

int main() {

    int n; // declare integer variable n
    printf("Enter a number: "); // prompt the user to enter a number
    scanf("%d", &n); // read the user input and store it in n

    if(n%2==0) {
        printf("%d is an even number.", n); // if n is even, print this message
    }
    else {
        printf("%d is an odd number.", n); // if n is odd, print this message
    }

    int sum = 0; // declare integer variable sum
    int i; // declare integer variable i

    for(i=1; i<=n; i++) {
        sum += i; // add i to sum
    }

    printf("\nThe sum of numbers from 1 to %d is %d", n, sum); // print the sum of numbers from 1 to n

    return 0; // indicate successful program completion
}