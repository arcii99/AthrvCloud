//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include<stdio.h>

void fibonacci(int n) { //function that generates fibonacci sequence
    int a = 0, b = 1, c, i;
    if(n == 0) //if n is 0, print 0
        printf("%d", a);
    else if(n == 1) //if n is 1, print 0 1
        printf("%d %d ", a, b);
    else {
        printf("%d %d ", a, b);
        for(i=2; i<n; i++) {
            c = a+b;
            printf("%d ", c);
            a = b;
            b = c;
        }
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of terms in Fibonacci sequence: ");
    scanf("%d", &n);
    fibonacci(n); //call the fibonacci function
    return 0;
}