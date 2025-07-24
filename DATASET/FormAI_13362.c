//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define an array containing potential fortunes
    char *fortunes[] = {
        "Good things come to those who wait",
        "A lifetime of happiness lies ahead of you",
        "Life is a journey, enjoy the ride",
        "Happiness is not something ready-made. It comes from your own actions",
        "Your future is looking bright",
        "You will meet someone special soon",
        "Keep trying, success is just around the corner",
        "Believe in yourself and all that you are",
        "Fortune favors the bold",
        "You are destined for greatness"
    };

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random index to access a fortune
    int index = rand() % 10;

    // Output the fortune to the user
    printf("Your fortune today: \n%s\n", fortunes[index]);

    return 0;
}