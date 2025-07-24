//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with current time
    srand(time(0));
    
    // Array of possible fortunes
    char* fortunes[] = {
        "You will find great success in love",
        "Someone close to you will receive a promotion",
        "You will travel to a foreign country",
        "You will win a large sum of money",
        "You will meet someone who will change your life",
        "You should be wary of making impulsive decisions",
        "You will learn a valuable lesson from a mistake you made",
        "You will discover a new hobby that brings you joy",
        "You will have a long and happy life",
        "You will overcome a difficult challenge"
    };
    
    // Generate a random number between 0 and 9
    int index = rand() % 10;
    
    // Output the fortune to the user
    printf("Your fortune for today is:\n");
    printf("%s\n", fortunes[index]);
    
    return 0;
}