//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Array of fortunes
    char *fortunes[] = {
        "You will have a successful career.",
        "A pleasant surprise is waiting for you.",
        "You will meet a new friend soon.",
        "You will fall in love with someone unexpected.",
        "Your hard work will pay off in the near future.",
        "A long journey is in store for you.",
        "You will receive a monetary gift.",
        "You will achieve your goals with ease.",
        "An exciting opportunity will present itself soon.",
        "You will make a new discovery." 
    };
    
    // Ask the user for their name
    char name[50];
    printf("Welcome to the Automated Fortune Teller! Please enter your name: ");
    scanf("%s", name);
    
    // Generate a random fortune
    int random_number = rand() % 10;
    char *fortune = fortunes[random_number];
    
    // Display the fortune to the user
    printf("\n\n%s, your fortune for today is: %s\n\n", name, fortune);
    
    return 0;
}