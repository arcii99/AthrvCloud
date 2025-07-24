//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int n, i, j, k, t1 = 0, t2 = 1, nextTerm;
    
    printf("\nEnter number of terms in Fibonacci series: ");
    scanf("%d", &n);
    
    printf("\n\nGenerating Fibonacci sequence: \n\n");
    
    for (i = 1; i <= n; i++) {
        
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        for (j = 0; j < nextTerm; j++) {
            
            for (k = 0; k < j; k++) {
                printf("* ");    // print * for each number in the sequence
                usleep(500);    // Add delay between each print for visual effect
            }
            
            printf("\n");    // print a new line after each row is complete
        }
        
        printf("\n");    // print an empty line to separate each row
    }
    
    return 0;
}