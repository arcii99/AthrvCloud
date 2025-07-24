//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the hilarious C Benchmarking program!\n");
    printf("In this benchmark, we will test how fast your computer is by measuring how quickly it can make a peanut butter and jelly sandwich.\n");

    srand(time(NULL));
    int jelly_amount = rand() % 100 + 1;
    int peanut_butter_amount = rand() % 100 + 1;

    printf("We will start by measuring how fast your computer spreads jelly on the bread.\n");
    printf("Your computer will start spreading %d grams of jelly...\n", jelly_amount);

    clock_t start_jelly = clock();
    for(int i = 0; i < jelly_amount; i++) {
        printf("Spreading jelly...%d grams done!\n", i+1);
    }
    clock_t end_jelly = clock();

    double jelly_time = (double)(end_jelly - start_jelly) / CLOCKS_PER_SEC;

    printf("Congratulations! Your computer spreads jelly at a speed of %f seconds per gram.\n\n", jelly_time/jelly_amount);

    printf("Now let's measure how fast your computer spreads peanut butter on the other side of the bread.\n");
    printf("Your computer will start spreading %d grams of peanut butter...\n", peanut_butter_amount);

    clock_t start_pb = clock();
    for(int i = 0; i < peanut_butter_amount; i++) {
        printf("Spreading peanut butter...%d grams done!\n", i+1);
    }
    clock_t end_pb = clock();

    double pb_time = (double)(end_pb - start_pb) / CLOCKS_PER_SEC;

    printf("Wow! Your computer spreads peanut butter at a speed of %f seconds per gram.\n\n", pb_time/peanut_butter_amount);

    double total_time = jelly_time + pb_time;
    printf("Overall, your computer took %f seconds to make a peanut butter and jelly sandwich.\n", total_time);
    printf("Let's convert that into a more relatable unit of measurement...\n");
    printf("Congratulations, your computer can make a peanut butter and jelly sandwich in %f days!\n", total_time/(60*60*24));
    
    return 0;
}