//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Bench-O-Tron 3000! The most powerful benchmarking tool on the planet!\n");
    printf("This program will test the speed of your computer by solving the toughest problem of all time...\n");
    printf("...finding out if a chicken or an egg comes first!\n\n");

    int result;    
    clock_t start_time, end_time;
    double total_time;
    srand(time(NULL));

    start_time = clock();
    for (int i = 0; i < 100000000; i++){
        int rand_num = rand() % 2; // Generate a random number
        if(rand_num == 0){
            result += 1; // Chicken comes first
        }else{
            result -= 1; // Egg comes first
        }
    }
    end_time = clock();

    total_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("The result is: ");
    if(result > 0){
        printf("Chicken comes first!\n");
    }else if (result < 0){
        printf("Egg comes first!\n");
    }else{
        printf("It's a tie!\n");
    }
    printf("Time taken to solve the problem: %lf seconds!\n", total_time);
    printf("Congratulations! Your computer is officially the fastest chicken-and-egg-solver in the universe!\n");
    printf("Thanks for using Bench-O-Tron 3000! Have a great day!\n");

    return 0;
}