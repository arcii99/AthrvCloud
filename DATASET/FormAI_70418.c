//FormAI DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATASET_SIZE 1000000
#define MAX_VALUE 1000

int main() {
    int dataset[DATASET_SIZE];
    int frequency[MAX_VALUE+1] = {0};
    srand(time(NULL));
    
    for(int i=0; i<DATASET_SIZE; i++) {
        dataset[i] = rand() % (MAX_VALUE+1);
    }
    
    clock_t start = clock();
    for(int i=0; i<DATASET_SIZE; i++) {
        frequency[dataset[i]]++;
    }
    clock_t end = clock();
    
    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken: %lf seconds\n", time_taken);
    
    int max_freq = frequency[0];
    int most_common_value = 0;
    
    for(int i=0; i<=MAX_VALUE; i++) {
        if(frequency[i] > max_freq) {
            max_freq = frequency[i];
            most_common_value = i;
        }
    }
    
    printf("Most common value: %d appeared %d times\n", most_common_value, max_freq);
    
    return 0;
}