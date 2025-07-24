//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FORTUNES_COUNT 6

// Define the list of fortunes
const char* fortunes[FORTUNES_COUNT] = {
   "You will find happiness in unexpected places",
   "A great opportunity will present itself in the near future",
   "Your hard work will pay off in the end",
   "The stars in the sky are aligned in your favor",
   "Do not be afraid to take risks",
   "A surprise is waiting for you around the corner"
};

int main() {
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Get a random index to determine which fortune to display
    int randomIndex = rand() % FORTUNES_COUNT;
    
    // Print the fortune to the user
    printf("Greetings, I am the automated fortune teller!\n\n");
    printf("Your fortune for today is: %s\n\n", fortunes[randomIndex]);
    
    return 0;
}