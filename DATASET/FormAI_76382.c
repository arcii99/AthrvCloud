//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    char* conspiracies[] = {
        "The government is hiding evidence of aliens in Area 51",
        "The moon landing was faked",
        "The Illuminati controls the world",
        "COVID-19 was created in a lab as a bio weapon",
        "Bigfoot is real and the government is hiding it from us",
        "The earth is flat",
        "The Titanic sinking was no accident",
        "The Bermuda Triangle is a portal to another dimension",
        "The Denver International Airport is a hub for the New World Order",
        "The Pyramids were built by aliens"
    };
    
    int num_conspiracies = sizeof(conspiracies) / sizeof(char*);
    
    printf("Welcome to the Random Conspiracy Theory Generator\n");
    
    while (1) {
        printf("Press enter to generate a new conspiracy theory or type 'exit' to quit\n");
        
        char input[256];
        fgets(input, 256, stdin);
        
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }
        
        int index = rand() % num_conspiracies; // select a random conspiracy theory
        printf("Your new conspiracy theory is: %s\n", conspiracies[index]);
    }
    
    return 0;
}