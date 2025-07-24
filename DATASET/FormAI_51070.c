//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Seed the random number generator

    // Array of fortunes
    char* fortunes[] = {
        "You will find happiness in unexpected places.",
        "A new career path will open up for you.",
        "Your hard work will pay off in the near future.",
        "A journey of a thousand miles begins with a single step.",
        "You will meet someone special soon.",
        "Financial success is on the horizon.",
        "Good things come to those who wait.",
        "A wise person knows how to laugh at themselves.",
        "You will have a pleasant surprise today.",
        "Don't be afraid to take risks.",
        "Your creativity will soon be rewarded.",
        "A bright future lies ahead."
    };

    // Generate a random number from 0 to 11
    int index = rand() % 12;

    // Print the fortune
    printf("Your fortune is: %s\n", fortunes[index]);

    return 0;
}