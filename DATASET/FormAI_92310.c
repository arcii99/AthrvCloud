//FormAI DATASET v1.0 Category: Benchmarking ; Style: sophisticated
#include <stdio.h>
#include <time.h>

int main() {

    int n = 10000000; // number of iterations
    clock_t start, end;
    double time_taken;

    /* Benchmarking 1 */
    start = clock(); // starting clock
    for(int i=0; i<n; i++) {
        /* simple loop */
    }
    end = clock(); // ending clock
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for simple loop of %d iterations: %lf seconds\n", n, time_taken);

    /* Benchmarking 2 */
    start = clock(); // starting clock
    for(int i=0; i<n; i++) {
        /* loop with arithmetic operations */
        int x = i*2 + 3;
    }
    end = clock(); // ending clock
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for loop with arithmetic operations of %d iterations: %lf seconds\n", n, time_taken);

    /* Benchmarking 3 */
    start = clock(); // starting clock
    for(int i=0; i<n; i++) {
        /* loop with conditionals */
        if(i%2==0 && i%3==0) {
            int x = i*2 + 3;
        }
    }
    end = clock(); // ending clock
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for loop with conditionals of %d iterations: %lf seconds\n", n, time_taken);

    /* Benchmarking 4 */
    start = clock(); // starting clock
    for(int i=0; i<n; i++) {
        /* loop with function calls */
        int x = i%10;
        int y = i/10;
        int z = x + y;
        int result = myFunction(z);
    }
    end = clock(); // ending clock
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for loop with function calls of %d iterations: %lf seconds\n", n, time_taken);

    return 0;
}

/* example function for function calls in benchmarking */
int myFunction(int x) {
    int y = x * 2;
    int z = y / 3;
    int w = z + 4;
    return w;
}