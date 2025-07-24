//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));  // initializing the random number generator
    float prob = (float)(rand() % 101);  // generating a random probability value between 0 and 100
    printf("Welcome to the Alien Invasion Probability Calculator 5000.\n");
    printf("The current probability of an alien invasion is %f percent.\n", prob);
    printf("Calculating the factors affecting the probability...\n");

    int num_factors = rand() % 6 + 5;  // generating a random number of factors between 5 and 10
    int i;
    for (i = 1; i <= num_factors; i++) {
        int factor = rand() % 10 + 1;  // generating a random factor value between 1 and 10
        printf("Factor %d: %d\n", i, factor);
        prob *= (float)factor / 10;  // updating the probability according to the factor value
    }

    printf("After considering all the factors, the new probability of an alien invasion is %f percent.\n", prob);

    if (prob >= 50.0) {
        printf("According to our calculations, an alien invasion is very likely to occur. \n");
        printf("Please take necessary precautions and prepare for the worst.\n");
    }
    else {
        printf("According to our calculations, an alien invasion is unlikely to occur at this time. \n");
        printf("However, it's always better to be safe than sorry. Keep an eye out for any suspicious activity.\n");
    }

    return 0;
}