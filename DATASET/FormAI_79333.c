//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Define array of possible fortunes
    char fortuneArr[10][50] = {"A great fortune is coming your way.",
                               "Today is your lucky day!",
                               "Good things come to those who wait.",
                               "Your future is looking bright.",
                               "Take care of your body and it will take care of you.",
                               "Travel is in your future.",
                               "You will overcome any obstacle in your path.",
                               "The best way to predict your future is to create it.",
                               "Life is a daring adventure, so go for it!",
                               "Be fearless in pursuit of what sets your soul on fire."};
    
    // Get the current time
    time_t t;
    time(&t);
    
    // Seed the random number generator with the current time
    srand((unsigned int) t);
    
    // Generate a random number between 0 and 9
    int fortuneIndex = rand() % 10;
    
    // Display the fortune to the user
    printf("Your fortune for today is:\n");
    printf("%s\n", fortuneArr[fortuneIndex]);
    
    // Exit the program
    return 0;
}