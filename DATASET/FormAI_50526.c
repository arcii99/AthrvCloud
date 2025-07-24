//FormAI DATASET v1.0 Category: Benchmarking ; Style: medieval
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the Medieval C Benchmarking Program!\n");
    printf("Press enter to start the test\n");
    getchar();

    clock_t start, end;
    int sum = 0;
    int i, j;

    start = clock();
    for(i = 0; i < 10000; i++){
        for(j = 0; j < 10000; j++){
            sum += j;
        }
    }
    end = clock();

    printf("The sum is: %d\n", sum);
    printf("The test took %f seconds\n", (float)(end-start)/CLOCKS_PER_SEC);

    return 0;
}