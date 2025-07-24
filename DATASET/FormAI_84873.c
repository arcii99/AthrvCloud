//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    
    // arrays of conspiracy theories
    char *theories1[] = {"The government is hiding the truth about", "Aliens have been", "There is a secret society dedicated to", "The moon landing was faked to cover up", "The Illuminati is behind the control of", "The world leaders are plotting to"};
    char *theories2[] = {"mind-controlling us through chemtrails", "building a secret underground base", "covering up the existence of intelligent life", "manipulating the stock market for their benefit", "creating a new world order", "harvesting organs for human cloning experiments"};
    char *theories3[] = {"in order to bring about the apocalypse", "as a means of achieving immortality", "while using technology stolen from a crashed UFO", "with the help of telepathic extraterrestrial beings", "to establish a totalitarian regime", "as part of a grand scheme to enslave humanity"};
    
    // generate random conspiracy theory
    int random1 = rand() % 6;
    int random2 = rand() % 6;
    int random3 = rand() % 6;
    printf("Did you know that %s %s %s?\n", theories1[random1], theories2[random2], theories3[random3]);
    
    return 0;
}