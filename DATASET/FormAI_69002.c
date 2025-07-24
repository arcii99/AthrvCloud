//FormAI DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>

int main() {

    printf("Welcome to the post-apocalyptic world!\n");
    printf("In this world, water is scarce and food is even scarcer.\n");
    printf("Your mission is to collect as much food as possible and survive.\n");

    int days = 0;
    int food_collected = 0;
    int food_consumed = 0;

    while (days < 7) {
        printf("Day %d\n", days);
        int food_found = rand() % 10 + 1;
        printf("You found %d food items today.\n", food_found);

        food_collected += food_found;
        food_consumed += rand() % 4 + 1;

        printf("You currently have %d food items.\n", food_collected);
        printf("You consumed %d food items today.\n", food_consumed);

        if (food_consumed >= food_collected) {
            printf("You have run out of food and died.\n");
            break;
        }

        days++;
    }

    if (days == 7 && food_consumed < food_collected) {
        printf("Congratulations! You have survived 7 days in the post-apocalyptic world!\n");
        printf("You collected %d food items and consumed %d food items.\n", food_collected, food_consumed);
    }

    return 0;
}