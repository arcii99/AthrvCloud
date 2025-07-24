//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double power(double num, int exp){
    double result = 1;
    int i;
    for(i = 0; i < exp; i++){
        result *= num;
    }
    return result;
}

double optimized_power(double num, int exp){
    if(exp == 0){
        return 1;
    }
    
    double result = num;
    int i;
    for(i = 1; i < exp; i++){
        result *= num;
    }
    return result;
}

int main()
{
    clock_t start1, end1, start2, end2;
    double num = 2.0;
    int exp = 100000000;
    
    // Performance test for power function
    start1 = clock();
    double result1 = power(num, exp);
    end1 = clock();
    
    // Performance test for optimized_power function
    start2 = clock();
    double result2 = optimized_power(num, exp);
    end2 = clock();
    
    printf("Result 1: %f\n", result1);
    printf("Time taken for power function: %f seconds\n", ((double) (end1 - start1)) / CLOCKS_PER_SEC);
    
    printf("Result 2: %f\n", result2);
    printf("Time taken for optimized_power function: %f seconds\n", ((double) (end2 - start2)) / CLOCKS_PER_SEC);
    
    return 0;
}