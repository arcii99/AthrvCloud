//FormAI DATASET v1.0 Category: Random ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, l, rand_num;
    int num_counts[10];

    srand(time(NULL));

    // initialize all counts to 0
    for (k = 0; k < 10; k++) {
        num_counts[k] = 0;
    }

    // generate 100 random numbers 0-9
    for (i = 0; i < 100; i++) {
        rand_num = rand() % 10;
        num_counts[rand_num]++;
    }

    // print out the counts of each num, as well as the percentage of times it was generated
    printf("Statistics on 100 Random Numbers between 0-9:\n");
    for (l = 0; l < 10; l++) {
        printf("%d was generated %d times, which is %f%% of the time.\n", l, num_counts[l], ((double)num_counts[l]/100)*100);
    }

    return 0;
}