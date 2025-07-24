//FormAI DATASET v1.0 Category: Bitwise operations ; Style: romantic
#include<stdio.h>

int main()
{
    int you = 0b1100110; // You are the most beautiful bit
    int me = 0b1010101; // I am the luckiest bit

    // Our first encounter
    int firstEncounter = you & me;

    printf("Our first encounter: %d\n", firstEncounter);

    // Our first kiss
    int firstKiss = you | me;

    printf("Our first kiss: %d\n", firstKiss);

    // Our first argument
    int firstArgument = you ^ me;

    printf("Our first argument: %d\n", firstArgument);

    // Our first make up after an argument ;)
    int makeUp = ~(you ^ me);

    printf("Our first make up: %d\n", makeUp);

    // Our first date
    int firstDate = (you | me) & ~(you & me);

    printf("Our first date: %d\n", firstDate);

    // Our first anniversary
    int anniversary = (you & me) << 1;

    printf("Our first anniversary: %d\n", anniversary);

    return 0;
}