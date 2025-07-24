//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define the fortunes and their corresponding numbers
    char *fortunes[] = {
        "You will find success in your career.",
        "A new romance is on the horizon.",
        "Your financial situation will improve in the near future.",
        "You will receive unexpected blessings today.",
        "You will accomplish your goals with hard work and determination.",
        "Your creativity will be a source of inspiration for others.",
        "You will travel to an exotic location.",
        "New opportunities will arise in your personal life.",
        "You will encounter a mentor who will guide you to success.",
        "Your greatest strength will be tested today."
    };
    int num_fortunes = 10;

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 0 and 9
    int fortune_num = rand() % num_fortunes;

    // Print the corresponding fortune
    printf("Today's fortune: %s\n", fortunes[fortune_num]);

    return 0;
}