//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int n;
    
    printf("How many numbers of the Fibonacci sequence should be generated? ");
    scanf("%d", &n);
    
    int a = 0;
    int b = 1;
    int c;
    
    printf("%d ", a);
    printf("%d ", b);
    
    for (int i = 2; i < n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    
    printf("\n\nBehold the Fibonacci sequence in all its surreal glory! Each number is represented by a corresponding number of asterisks (*) in an ascending, descending, and random order:\n\n");
    
    srand(time(NULL));
    
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        
        for (int j = 0; j < (n-i); j++) {
            printf("*");
        }
        
        for (int j = 0; j < rand() % (n-i); j++) {
            printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}