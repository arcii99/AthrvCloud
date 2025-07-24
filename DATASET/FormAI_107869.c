//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Get ready for your mind to be blown! Here comes the Random Conspiracy Theory Generator!\n");
    srand(time(NULL));  // initialize random seed
    char* nouns[] = {"government", "aliens", "Illuminati", "Big Pharma", "deep state", "the media", "the elite", "Freemasons", "the internet", "tech companies", "food industry", "weather control machine", "flat earth believers", "artificial intelligence", "time travelers", "future humans"};
    char* adjectives[] = {"secretly controls", "manipulates", "brainwashes", "spies on", "corrupts", "poisons", "hacks", "blackmails", "silences", "creates", "alters", "monitors", "influences", "terrifies", "destroys", "remakes"};
    char* events[] = {"9/11", "moon landing", "JFK assassination", "COVID-19 pandemic", "Area 51", "Roswell crash", "Bermuda Triangle", "deep sea creature sightings", "crop circles", "Sandy Hook shooting", "Chemtrails", "Holocaust", "global warming", "Mayan calendar", "Mt Everest deaths", "Australian bushfires"};
    char* theories[] = {"to start a new world order", "to enslave humanity", "to control natural resources", "to test bioengineering weapons", "to establish a space colony", "to create a utopia for the chosen ones", "to bring about the end of the world", "to merge humans with machines", "to manipulate time and space", "to force evolutionary leap", "to seek cosmic truth"};
    
    for(int i = 0; i < 5; ++i) {  // generate 5 random conspiracy theories
        printf("\n\nConspiracy Theory #%d:\n", i+1);
        int n = rand() % 16;  // choose a random noun
        int adj = rand() % 16;  // choose a random adjective
        int evt = rand() % 16;  // choose a random event
        int thr = rand() % 11;  // choose a random theory
        printf("The %s %s %s %s!\n", nouns[n], adjectives[adj], events[evt], theories[thr]);
        if(n == 0 && adj == 0 && evt == 0 && thr == 0) {
            printf("Oh, wait, that's not a theory, that's just common knowledge...\n");
        }
    }
    return 0;
}