//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Amazing Automated Fortune Teller!\n");

    //random number generator seed
    srand(time(NULL));

    //array of fortunes
    char *fortunes[] = {"You will find love in the most unexpected place.",
                        "You will receive a promotion at work soon.",
                        "Try not to trip today.",
                        "You will have a great hair day tomorrow.",
                        "Watch out for falling objects today.",
                        "Good news will come your way tomorrow.",
                        "You will find money on the ground today.",
                        "Avoid wearing green tomorrow.",
                        "You will achieve great success in the future.",
                        "Watch your back today."
                       };

    //get random fortune index
    int index = rand() % 10;
    char *fortune = fortunes[index];

    printf("Your fortune for today is: \n%s\n", fortune);

    return 0;
}