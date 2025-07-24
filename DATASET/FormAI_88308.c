//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateConspiracyTheory() {
    char* topics[] = {"Moon landing was fake", "Aliens exist and the government is hiding it", 
                      "9/11 was an inside job", "Vaccines cause autism", 
                      "The Earth is flat", "Chemtrails are poisoning us", 
                      "Bigfoot is real and the government is covering it up"};

    char* evidence[] = {"There are no stars in the background of the moon landing photos",
                        "I saw a UFO once", "Jet fuel can't melt steel beams",
                        "I read about it on a blog", "The curvature of the Earth is not visible",
                        "I saw planes leaving trails in the sky", "I saw Bigfoot with my own eyes"};

    char* people[] = {"The Illuminati", "The government", "The lizard people", "The Freemasons", 
                      "The deep state", "The New World Order", "The Reptilians"};

    srand(time(NULL));
    int topicIndex = rand() % 7;
    int evidenceIndex = rand() % 7;
    int peopleIndex = rand() % 7;

    printf("Did you know that %s is %s because of %s?\n", topics[topicIndex], 
           (rand() % 2) ? "true" : "false", evidence[evidenceIndex]);
    printf("And who is behind it all? You guessed it - %s!\n", people[peopleIndex]);
}

int main() {
    for(int i = 0; i < 10; i++) {
        generateConspiracyTheory();
    }
    return 0;
}