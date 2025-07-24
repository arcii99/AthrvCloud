//FormAI DATASET v1.0 Category: Random ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000 // maximum number of random integers to generate
#define BINS 10 // number of bins for histogram

int main() {
    // initialize random number generator with current time as seed
    srand(time(NULL)); 

    // initialize variables
    int rand_num, max_num = 0, min_num = RAND_MAX;
    double avg_num = 0;
    int bin_counts[BINS] = {0};
    int i;

    // generate random numbers and keep track of statistics
    printf("Generating random numbers...\n");
    for (i = 0; i < MAX; i++) {
        rand_num = rand(); // generate random integer
        if (rand_num > max_num) max_num = rand_num; // update max number
        if (rand_num < min_num) min_num = rand_num; // update min number
        avg_num += (double)rand_num/MAX; // update average number
        // update bin counts for histogram
        bin_counts[(int)(((double)rand_num/RAND_MAX)*(BINS-1))]++; 
    }

    // print results
    printf("Statistics:\n");
    printf("Maximum number: %d\n", max_num);
    printf("Minimum number: %d\n", min_num);
    printf("Average number: %lf\n", avg_num);
    printf("Histogram:\n");
    printf("Range\tCount\n");
    for (i = 0; i < BINS; i++) {
        printf("%d-%d\t%d\n", (int)((double)RAND_MAX/BINS)*i, (int)((double)RAND_MAX/BINS)*(i+1)-1, bin_counts[i]);
    }

    return 0;
}