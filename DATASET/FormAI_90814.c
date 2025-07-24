//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));  // seed the random number generator with the current time

    // array of possible fortunes
    char* fortunes[] = {
        "You will meet someone special today.",
        "A new opportunity will present itself to you soon.",
        "Your hard work will pay off in the near future.",
        "Your creativity will be recognized and rewarded.",
        "Good things come to those who persevere.",
        "Take time to enjoy the simple pleasures in life.",
        "Happiness is just around the corner.",
        "Meeting a stranger today will bring you great fortune.",
        "This year will be full of new opportunities and growth.",
        "An unexpected adventure awaits you.",
        "Luck is on your side, take a chance.",
        "Your kindness will be greatly appreciated.",
        "A long-awaited dream will come true this year."
    };

    // get the number of elements in the fortunes array
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);

    // generate a random number within the range of the fortunes array
    int random_index = rand() % num_fortunes;

    // print the fortune for this session
    printf("Welcome to the Brave Automated Fortune Teller!\n");
    printf("Your fortune for today is:\n\n%s\n", fortunes[random_index]);

    return 0;
}