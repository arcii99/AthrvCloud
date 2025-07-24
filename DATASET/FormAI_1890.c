//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i = 0, j = 0, k = 0, n = 0, m = 0, rand_num = 0;
    int num_words = 20;
    char *words[] = {"government", "aliens", "Illuminati", "secret societies", "New World Order", "Big Pharma",
                     "mind control", "global warming", "chemtrails", "HAARP", "fluoride", "vaccines", "9/11", 
                     "moon landing", "FEMA camps", "Nibiru", "Mandela effect", "Area 51", "hollywood", "CIA"};
    char *prefix[] = {"They", "The government", "The ruling elite", "The shadow government", "The higher-ups",
                      "The powers that be", "The Illuminati", "The New World Order", "The reptilians", "The aliens",
                      "The deep state", "The globalists", "The cabal", "The Freemasons", "The Bilderberg group",
                      "The Council on Foreign Relations", "The Trilateral Commission", "The Bohemian Grove",
                      "The Knights Templar", "The Skull and Bones society"};
    char *phrase[] = {"is secretly controlling", "has planned", "is manipulating",
                      "is hiding the truth about", "created", "caused", "wants to hide"};
    char *suffix[] = {"vaccines", "9/11", "climate change", "alien abductions", "bigfoot", "chemtrails",
                      "mind control", "the moon landing", "the JFK assassination", "the Bermuda Triangle",
                      "the Loch Ness monster", "the existence of mermaids", "Area 51", "the Illuminati",
                      "the Mandela effect", "the flat earth", "the existence of ghosts", "flouridation",
                      "the use of HAARP", "the existence of Nibiru"};

    srand(time(NULL));  // seed for random number generator

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    // generate 10 random conspiracy theories
    for (i = 1; i <= 10; i++) {
        printf("%d) ", i);

        // generate random prefix
        rand_num = rand() % 20;
        printf("%s ", prefix[rand_num]);

        // generate random phrase
        rand_num = rand() % 7;
        printf("%s ", phrase[rand_num]);

        // generate random suffix
        rand_num = rand() % 20;
        printf("%s.\n", suffix[rand_num]);

        // generate random number of related words
        n = rand() % num_words + 1;

        // print related words
        printf("   - Related words: ");
        for (j = 0; j < n; j++) {
            m = rand() % num_words;
            printf("%s", words[m]);
            if (j != n - 1) {
                printf(", ");
            }
        }
        printf("\n");

        printf("\n");  // add a space between theories
    }

    return 0;
}