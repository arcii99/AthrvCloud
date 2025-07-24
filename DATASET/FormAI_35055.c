//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* fortunes[] = {
    "Good things come to those who wait.",
    "The early bird catches the worm.",
    "You will receive a pleasant surprise.",
    "Your future looks bright!",
    "A journey of a thousand miles begins with a single step.",
    "You will find success in your endeavors.",
    "The best way to predict your future is to create it.",
    "You will overcome your greatest fear.",
    "Now is the time to try something new.",
    "A wise person learns from others' mistakes.",
    "You will soon meet someone important."
};

int main()
{
    srand(time(NULL));
    int randomNumber = rand() % 11;
    printf("\nWelcome to the Automated Fortune Teller.\n\n");
    printf("Your fortune for the day is: %s\n\n", fortunes[randomNumber]);
    return 0;
}