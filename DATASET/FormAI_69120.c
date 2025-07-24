//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generate a conspiracy theory
char* generate_conspiracy() {
    char* conspiracy[10] = { 
        "The moon landing was faked",
        "Aliens are living among us",
        "9/11 was an inside job",
        "The earth is flat",
        "Chemtrails are a government conspiracy",
        "The illuminati control the world",
        "The government is hiding the cure to cancer",
        "Elvis is still alive",
        "The Bermuda Triangle is a portal to another dimension",
        "Bigfoot exists and is being hidden by the government"
    };
    
    srand(time(NULL)); // seed the random number generator with the current time
    int rand_index = rand() % 10; // choose a random index between 0 and 9
    char* rand_conspiracy = conspiracy[rand_index]; // get the conspiracy theory at that index
    return rand_conspiracy;
}

int main() {
    // Welcome message
    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    // Get user's name
    printf("What's your name?\n");
    char name[20];
    fgets(name, 20, stdin);

    // Generate a random conspiracy theory and display it to the user
    char* conspiracy = generate_conspiracy();
    printf("Hi %s, here's a random conspiracy theory for you:\n%s\n", name, conspiracy);

    return 0;
}