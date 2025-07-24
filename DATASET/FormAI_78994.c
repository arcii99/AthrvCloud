//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initializes the random seed
    
    int i;
    char *theories[] = {
        "The moon landing was faked",
        "The government is controlling our minds with chemtrails",
        "Aliens have infiltrated the government",
        "The Earth is flat",
        "The Illuminati controls everything",
        "The government created AIDS as a way to control population",
        "9/11 was an inside job",
        "Elvis Presley is still alive",
        "The Bermuda Triangle is a portal to another dimension",
        "The Loch Ness Monster is real",
        "The ancient Egyptians had help from aliens to build the pyramids",
        "The world will end in 2012 (oops, too late)",
        "Bigfoot is a government experiment gone wrong",
        "The Titanic didn't sink, it was its sister ship the Olympic",
        "Paul McCartney died in 1966 and was replaced by a lookalike",
        "The government has a secret time travel program",
        "The Denver airport is a secret underground bunker for the elite",
        "JFK's assassination was a CIA plot",
        "The Mandela Effect proves we're living in a parallel universe",
        "Chemtrails are turning people into zombies",
    };
    int num_theories = sizeof(theories) / sizeof(theories[0]); // calculates the number of theories in the array
    
    printf("Here's your random conspiracy theory of the day:\n\n");
    
    for (i = 0; i < 3; i++) { // prints 3 random theories
        int index = rand() % num_theories; // generates random number between 0 and num_theories - 1
        printf("%d. %s\n", i+1, theories[index]); // prints the theory
    }
    
    return 0;
}