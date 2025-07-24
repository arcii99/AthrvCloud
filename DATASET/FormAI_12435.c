//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator   

    char *nouns[] = {"government", "aliens", "Illuminati", "Big Pharma", "Masons", "New World Order", "Reptilians", "Zionists", "Freemasons", "Deep State"};
    char *verbs[] = {"control", "manipulate", "poison", "brainwash", "spy on", "enslave", "conspire against", "experiment on", "infiltrate", "destroy"};
    char *adjectives[] = {"secret", "corrupt", "powerful", "dangerous", "hidden", "sinister", "mysterious", "malevolent", "shadowy", "evil"};
    char *theories[] = {"chemtrails are used to control the population", "9/11 was an inside job", "Area 51 hides evidence of aliens", "fluoride in the water is poisonous", "vaccines cause autism", "the moon landing was faked", "COVID-19 is a hoax", "climate change is a myth", "the government is hiding the cure for cancer", "Elvis Presley is still alive"};
    
    printf("Random Conspiracy Theory Generator\n");
    printf("-------------------------------\n\n");
    
    for (int i = 0; i < 5; i++) {
        int noun_idx = rand() % 10;
        int verb_idx = rand() % 10;
        int adj_idx = rand() % 10;
        int theory_idx = rand() % 10;
    
        printf("%d. The %s %s %s because they are %s.\n", i+1, adjectives[adj_idx], nouns[noun_idx], verbs[verb_idx], theories[theory_idx]);
        
        // generate a sprinkle of random punctuation
        int punct_chance = rand() % 100;
        if (punct_chance < 30) { // 30% chance of a question mark
            printf("?");
        } else if (punct_chance < 60) { // 30% chance of an exclamation mark
            printf("!");
        } else if (punct_chance < 80) { // 20% chance of a period
            printf(".");
        } else { // 20% chance of no punctuation
            printf(" ");
        }
        
        printf("\n\n");
    }
    
    return 0;
}