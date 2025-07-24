//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: realistic
#include <stdio.h>

int main() {
    int n,i;
    int a,b,c;

    printf("Enter the number of terms for the Fibonacci sequence: ");
    scanf("%d", &n);

    if(n<1) {
        printf("The number of terms must be greater than 0\n");
        return 1;
    }

    printf("The first %d terms of the Fibonacci sequence are:\n", n);

    a=0;
    b=1;

    //Print the first two terms since they are predefined
    printf("%d, %d, ", a, b);

    for(i=3;i<=n;i++) {
        c=a+b;
        
        if(c<0) {
            printf("\nOverflow occurred at %d terms\n", i);
            return 1;
        }

        printf("%d, ", c);

        a=b;
        b=c;
    }

    printf("\n");

    return 0;
}