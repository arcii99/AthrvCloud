//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random conspiracy theory
char* generate_conspiracy_theory() {
    char* theories[] = {
        "The government is spying on us through our smartphones.",
        "The moon landing was faked.",
        "The earth is actually flat.",
        "The Illuminati controls the world.",
        "The coronavirus was created in a lab.",
        "Aliens are among us and the government is covering it up.",
        "The Loch Ness monster is real and the government is hiding it.",
        "The Bermuda triangle is a gateway to another dimension.",
        "The pyramids were built by aliens.",
        "The government is hiding the cure for cancer."
    };
    
    // get the size of the array of theories
    int size = sizeof(theories) / sizeof(theories[0]);
    
    // generate random number
    srand(time(NULL));
    int index = rand() % size;
    
    // return the conspiracy theory
    return theories[index];
}

int main() {
    // print a cheerful message
    printf("Welcome to the random conspiracy theory generator!\n\n");
    
    // generate and print a random conspiracy theory
    printf("Did you know that...\n%s\n\n", generate_conspiracy_theory());
    
    // print a cheerful goodbye message
    printf("Thanks for using the random conspiracy theory generator. Stay woke!\n");
    
    return 0; // exit program
}