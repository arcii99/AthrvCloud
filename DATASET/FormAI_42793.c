//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(0)); //initialize random seed
    
    //List of conspiracy theories
    char* theories[10] = {"The moon landing was faked by the government.",
                          "The earth is flat.",
                          "The Illuminati control the world.",
                          "Aliens exist and the government is covering it up.",
                          "9/11 was an inside job.",
                          "The vaccine for the pandemic was created before the pandemic.",
                          "The government is controlling the weather.",
                          "The royal family are actually aliens.",
                          "The Loch Ness Monster exists and the government is hiding it.",
                          "Elvis Presley faked his own death."};
    
    //List of countries that are conspiring
    char* countries[10] = {"Russia",
                           "China",
                           "North Korea",
                           "Iran",
                           "Israel",
                           "Mexico",
                           "Canada",
                           "United Kingdom",
                           "France",
                           "Germany"};
    
    //List of actions being taken by the conspirators
    char* actions[10] = {"Brainwashing the masses through media",
                         "Controlling the financial system",
                         "Creating diseases in a lab",
                         "Hacking into government systems",
                         "Rigging elections",
                         "Releasing toxic chemicals into the environment",
                         "Conducting secret experiments on humans",
                         "Manipulating the stock market",
                         "Creating technology to control people's minds",
                         "Using mind control to influence world leaders"};
    
    //Generate random conspiracy theory using components from above lists
    int rand_theory = rand() % 10;
    int rand_country = rand() % 10;
    int rand_action = rand() % 10;
    
    //Output the conspiracy theory
    printf("According to my sources, %s is conspiring with %s to %s.\n", countries[rand_country], theories[rand_theory], actions[rand_action]);
    
    return 0;
}