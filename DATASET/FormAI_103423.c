//FormAI DATASET v1.0 Category: Random ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int status;
} Result;

void randomGenerator(Result* res) {
    res->value = (rand() % 100) + 1;
    res->status = 1;
}

int main() {
    srand(time(NULL));
    Result res;

    printf("Starting random generator...\n\n");

    #pragma omp parallel num_threads(2)
    {
        #pragma omp for
        for(int i=0; i<10; i++) {
            randomGenerator(&res);
            if(res.status == 1) {
                printf("Iteration %d: %d\n", i+1, res.value);
            } else {
                printf("Iteration %d: Failed to generate random number\n", i+1);
            }
        }
    }

    printf("\nRandom generator stopped.\n");
    return 0;
}