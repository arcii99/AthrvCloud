//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: visionary
#include<stdio.h>

// Function to generate Fibonacci Sequence
void fib(int n){
    int a = 0, b = 1, c, i;
    printf("%d %d ", a, b);

    for(i=2;i<n;i++){
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

// Function to visualize Fibonacci sequence using asterisks(*)
void visualize(int n){
    int a = 0, b = 1, c, i, j, k, space = n;

    for(i=0;i<n;i++){
        for(j=0;j<space;j++){
            printf(" ");
        }
        for(k=0;k<=i;k++){
            c = a + b;
            printf("* ");
            a = b;
            b = c;
        }
        printf("\n");
        space--;
    }
}

int main(){
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("\nGenerating Fibonacci Sequence...\n");
    fib(n);

    printf("\n\nVisualizing Fibonacci Sequence...\n");
    visualize(n);

    return 0;
}