//FormAI DATASET v1.0 Category: Arithmetic ; Style: scientific
/*
Arithmetic Progression Series Calculator
Designed to calculate the arithmetic series given the number of terms and the common difference.
Formula: S_N = (N/2)(a_1 + a_N)
         a_N = a_1 + (N-1)d
         
Where:
S_N = sum of arithmetic series
N = number of terms
a_1 = first term
a_N = nth term
d = common difference

*/

#include <stdio.h>

int main() {
    
    // initialize variables
    int N, a_1, a_N, d, S_N = 0;
    
    // prompt user input
    printf("Enter the number of terms: ");
    scanf("%d", &N);
    
    printf("Enter the first term: ");
    scanf("%d", &a_1);
    
    printf("Enter the common difference: ");
    scanf("%d", &d);
    
    // calculate a_N and S_N
    a_N = a_1 + (N-1)*d;
    S_N = (N/2)*(a_1 + a_N);
    
    // print results
    printf("First term: %d\n", a_1);
    printf("Common difference: %d\n", d);
    printf("Number of terms: %d\n", N);
    printf("Nth term: %d\n", a_N);
    printf("Sum of series: %d\n", S_N);
    
    return 0;
}