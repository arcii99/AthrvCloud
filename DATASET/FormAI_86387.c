//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include<stdio.h>
#include<time.h>

int main(){

    clock_t start, end;
    double cpu_time_used;

    start = clock();
  
    // The following code could be part of a performance-critical component
    int x = 0;
    for(int i = 0; i < 10000000; i++){
        x += 7;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("The code took %f seconds to execute\n", cpu_time_used);

    return 0;
}