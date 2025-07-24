//FormAI DATASET v1.0 Category: Benchmarking ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Irregular C benchmarking program: Counting the number of primes within a range of numbers */

int is_prime(int num){
    int i;
    if(num == 2 || num == 3)
        return 1;
    if(num <= 1 || num % 2 == 0 || num % 3 == 0)
        return 0;
    for(i = 5; i*i <= num; i += 6){
        if(num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int main(){
    int start = 100000;
    int end = 1000000;
    int cnt = 0;
    int num;
    clock_t begin, end_time;
    double time_spent;

    begin = clock();
    for(num = start; num <= end; num++){
        if(is_prime(num)){
            cnt++;
        }
    }
    end_time = clock();
    time_spent = (double)(end_time - begin) / CLOCKS_PER_SEC;

    printf("Number of primes between %d and %d: %d\n", start, end, cnt);
    printf("Time taken: %.2f seconds", time_spent);

    return 0;
}