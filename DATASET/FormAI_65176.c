//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the max number of fortunes
#define MAX_FORTUNES 10

// Define the length of each fortune
#define FORTUNE_LENGTH 100

// Initialize the array of fortunes
char fortunes[MAX_FORTUNES][FORTUNE_LENGTH] = {
    "A great opportunity lies ahead.",
    "You will meet someone special in the near future.",
    "Your hard work will pay off in the end.",
    "Your creativity will lead to success.",
    "A major life-changing event is coming soon.",
    "You will soon receive unexpected good news.",
    "Your positive attitude will bring you happiness.",
    "A small trip will bring you great joy.",
    "Trust your intuition when making decisions.",
    "Your dedication and perseverance will lead to a promotion."
};

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Generate a random number between 0 and MAX_FORTUNES - 1
    int random_number = rand() % MAX_FORTUNES;
    
    // Print the fortune
    printf("Your fortune for today is: %s\n", fortunes[random_number]);
    
    return 0;
}