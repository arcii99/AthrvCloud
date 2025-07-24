//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *theories[10] = {"The moon landing was faked",
                          "The government is run by aliens",
                          "Bigfoot is a government experiment",
                          "Chemtrails are mind control agents",
                          "The earth is flat",
                          "The Illuminati controls everything",
                          "Vaccines cause autism",
                          "9/11 was an inside job",
                          "The Loch Ness monster is real",
                          "Area 51 houses extraterrestrial technology"};
                
    srand(time(NULL)); // seed random number generator with current time
    int randomIndex = rand() % 10; // generate random number from 0 to 9
    printf("Random conspiracy theory: %s\n", theories[randomIndex]);
    
    return 0;
}