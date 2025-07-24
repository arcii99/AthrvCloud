//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *conspiracies[] = {"The moon landing was faked", "Chemtrails control our minds", "The Illuminati runs the world", "9/11 was an inside job", "Bigfoot is real", "The Earth is flat"};
    char *government_figures[] = {"The President", "The Vice President", "The Secretary of State", "The Director of the FBI", "The Attorney General"};
    char *random_figure;
    char *random_conspiracy;
    
    srand(time(NULL));
    
    for (int i=0; i<5; i++) {
        random_figure = government_figures[rand() % 5];
        random_conspiracy = conspiracies[rand() % 6];
        
        printf("%s is secretly involved in %s.\n", random_figure, random_conspiracy);
    }
    
    return 0;
}