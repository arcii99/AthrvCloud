//FormAI DATASET v1.0 Category: Arithmetic ; Style: mathematical
/* 
   This program computes the sum of the first N terms of the arithmetic sequence 
   a, a+d, a+2d, a+3d, ..., where a is the first term, d is the common difference, 
   and N is the number of terms to sum. 
   
   It also computes the average of these N terms and the sum of the squares of 
   the first N terms. 
   
   The user is prompted to enter the values of a, d, and N.
*/

#include <stdio.h>

int main() {
    int a, d, N, i;
    double sum = 0, avg, sum_squares = 0;
    
    printf("Enter the first term of the arithmetic sequence: ");
    scanf("%d", &a);
    
    printf("Enter the common difference of the arithmetic sequence: ");
    scanf("%d", &d);
    
    printf("Enter the number of terms to sum: ");
    scanf("%d", &N);
    
    for (i = 0; i < N; i++) {
        sum += a + i*d;
        sum_squares += (a + i*d) * (a + i*d);
    }
    
    avg = sum / N;
    
    printf("\n");
    printf("The sum of the first %d terms is: %f\n", N, sum);
    printf("The average of the first %d terms is: %f\n", N, avg);
    printf("The sum of the squares of the first %d terms is: %f\n", N, sum_squares);
    
    return 0;
}