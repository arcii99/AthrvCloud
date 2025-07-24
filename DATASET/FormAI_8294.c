//FormAI DATASET v1.0 Category: Random ; Style: excited
// Oh boy, are you ready to see some random magic?!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Get ready to see some amazing randomness in action!
   
    printf("Welcome to the random world!\n");
   
    // Set the seed based on current time
    srand(time(NULL));
   
    // Let's generate some random numbers!
    for (int i = 1; i <= 10; i++) {
        int random_number = rand();
        printf("Random number #%d: %d\n", i, random_number);
    }

    // Random numbers are cool and all, but let's make things more interesting...
    printf("Time for some coin flipping action!\n");
   
    // Let's use our random number generator to simulate some coin flips!
    for (int i = 1; i <= 5; i++) {
        int coin_flip = rand() % 2;
        if (coin_flip == 0) {
            printf("Coin flip #%d: Heads\n", i);
        } else {
            printf("Coin flip #%d: Tails\n", i);
        }
    }

    // Let's spice things up even more with some random colors!
    printf("You know what's boring? Fixed colors. Let's make them random!\n");
   
    // Generate random RGB values for our color
    int red = rand() % 256;
    int green = rand() % 256;
    int blue = rand() % 256;
   
    printf("Your random color is: #%02X%02X%02X\n", red, green, blue);

    // That's not enough randomness for you? Let's combine some of our previous randomness!
    printf("It's time to roll some dice!\n");
   
    // Let's roll two dice and see what we get
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int sum = dice1 + dice2;
   
    printf("You rolled a %d and a %d. Total: %d\n", dice1, dice2, sum);

    // I hope you're as excited as I am about all this randomness! 
    printf("Thanks for exploring the wonderful world of C randomization with me!\n");
   
    return 0;
}