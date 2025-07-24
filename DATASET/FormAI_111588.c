//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Array of fortunes
    char *fortunes[] = {
        "You will find great success in your future.",
        "Hardships are on the horizon, but you will overcome them.",
        "New opportunities are coming your way, don't miss out.",
        "Be cautious with your finances in the coming weeks.",
        "Love is in the air for you, keep your eyes open.",
        "Great things come to those who wait, be patient.",
        "Your creative talents will soon be recognized.",
        "A new adventure awaits you in the near future.",
        "You will have unexpected visitors in the coming days.",
        "Your hard work is about to pay off, keep going."
    };

    // Randomly choose a fortune from the array
    int random_index = rand() % 10;
    char *chosen_fortune = fortunes[random_index];

    // Print the fortune
    printf("Your fortune for today: %s\n", chosen_fortune);

    return 0;
}