//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(0));

    // Declare and initialize arrays for parts of the conspiracy theory
    char *subject[] = {"The Moon Landing", "The Illuminati", "Chemtrails", "9/11", "Area 51", "Bigfoot", "The New World Order", "Roswell", "The Mandela Effect", "The Rothschilds"};
    char *verb[] = {"are controlling", "are manipulating", "are hiding", "are planning", "are covering up", "are hoarding", "are creating", "are experimenting with", "are threatening", "are brainwashing"};
    char *object[] = {"our government", "our minds", "the weather", "our future", "aliens", "the truth", "the economy", "history", "the media", "the education system"};

    // Generate a random combination of the arrays and print it out
    printf("Did you know that %s %s %s?\n", subject[rand() % 10], verb[rand() % 10], object[rand() % 10]);
    printf("It's true! Wake up sheeple!\n");

    return 0;
}