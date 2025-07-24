//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    //create an array of 20 fortunes
    char *fortunes[] = {
        "You will soon embark on a great adventure.",
        "Your hard work will pay off in the near future.",
        "You will find love in unexpected places.",
        "Good news is on the horizon!",
        "Your creative talents will soon be recognized.",
        "You will achieve success in your chosen field.",
        "A new opportunity is coming your way.",
        "Today is a good day to try something new.",
        "You will be surprised by a sudden windfall.",
        "Your kindness will be rewarded.",
        "Someone close to you will bring you joy.",
        "A happy surprise is in store for you.",
        "Your determination will lead to success.",
        "You will overcome a difficult challenge.",
        "Your future is bright with promise.",
        "A journey taken with a loved one is in your future.",
        "Good things come to those who wait.",
        "Your positive attitude will lead to good things.",
        "The future holds great promise for you.",
        "A long-held dream will soon become a reality."
    };

    //initialize random number generator
    srand(time(NULL));

    //generate a random index to pick a fortune from the array
    int index = rand() % 20;

    //print the fortune
    printf("Your fortune for today is:\n");
    printf("%s\n", fortunes[index]);

    return 0;
}