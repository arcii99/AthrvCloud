//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: inquisitive
#include<stdio.h>

int main(){
    int n, a = 0, b = 1, c = 0;
    printf("Enter the number of terms to be printed in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\nThe Fibonacci sequence for the first %d terms is:\n", n);

    // Printing the first two terms
    printf("%d, %d, ", a, b);

    // Printing the rest of the terms
    for(int i=3; i<=n; i++){
        c = a + b;
        a = b;
        b = c;
        printf("%d, ", c);
    }

    // Visualizing the sequence
    printf("\n\n\nHere is the Fibonacci sequence visualized:\n\n");

    // Looping through each row
    for(int i=1; i<=n; i++){
        // Looping through each column
        for(int j=1; j<=i; j++){
            // Calculating the current term
            int term;
            if(j==1 || j==2) term = 1;
            else term = term = a + b;
            a = b;
            b = term;

            // Printing the current term
            printf("%d ", term);
        }
        printf("\n");
    }
    return 0;
}