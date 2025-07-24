//FormAI DATASET v1.0 Category: Benchmarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used_largest = -1;
    double cpu_time_used_smallest = 1E6;

    for(int i=0; i<100; i++){
        start = clock(); // start the clock
        
        // generate large random prime number using Miller-Rabin Algorithm
        int n = rand() % 500000; 
        while(1){
            int a = rand() % (n-3) + 2;
            int k = n-1;
            while(k%2 == 0){
                if(fmod(pow(a, k/2), n) == n-1) break;
                k /= 2;
            }
            if(k == 1 || fmod(pow(a,k), n) == 1) continue;
            for(int j=0; j<k; j++){
                if(fmod(pow(a, pow(2,j)*k), n) == n-1) break;
                if(j == k-1) goto PRIME;
            }
        }
        PRIME:
        end = clock(); // stop the clock
        double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate the time used
        if(cpu_time_used > cpu_time_used_largest) cpu_time_used_largest = cpu_time_used;
        if(cpu_time_used < cpu_time_used_smallest) cpu_time_used_smallest = cpu_time_used;
        printf("Prime number found in %f seconds\n", cpu_time_used);
    }

    printf("Largest time used: %f\n", cpu_time_used_largest);
    printf("Smallest time used: %f\n", cpu_time_used_smallest);

    return 0;
}