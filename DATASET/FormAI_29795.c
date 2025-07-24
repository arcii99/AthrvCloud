//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACIES 10
#define MAX_LENGTH 200

char *conspiracies[MAX_CONSPIRACIES] = {
    "The moon landing was faked",
    "Chemtrails are controlling our minds",
    "Aliens are controlling the government",
    "The Earth is flat",
    "The Illuminati control everything",
    "9/11 was an inside job",
    "The government is hiding evidence of intelligent life on Mars",
    "The vaccine for COVID-19 has a microchip that tracks you",
    "The Bermuda Triangle is a portal to another dimension",
    "Bigfoot is real and the government is covering it up"
};

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    printf("Welcome to the C Random Conspiracy Theory Generator!\n\n");
    
    while(1) { // loop forever
        printf("Type 'q' to quit or 'g' to generate a conspiracy theory: ");
        char input[MAX_LENGTH]; // create a char array to hold the user's input
        fgets(input, MAX_LENGTH, stdin); // read the user's input from the console
        input[strcspn(input, "\n")] = 0; // remove the newline character from the end of the string
        
        if(strcmp(input, "q") == 0) { // if the user types 'q', exit the program
            printf("\nExiting...\n");
            break;
        }
        
        if(strcmp(input, "g") == 0) { // if the user types 'g', generate a conspiracy theory
            int index = rand() % MAX_CONSPIRACIES; // pick a random index from the conspiracies array
            printf("Your conspiracy theory is: %s\n\n", conspiracies[index]);
        }
    }
    
    return 0;
}