//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    
    // Declare arrays of conspiracy theories and entities involved
    char* conspiracy_theories[] = {
        "The moon landing was faked.",
        "The government is hiding evidence of extraterrestrial life.",
        "COVID-19 was created in a lab.",
        "9/11 was an inside job.",
        "The Illuminati controls world affairs.",
    };
    
    char* entities_involved[] = {
        "The CIA",
        "The Freemasons",
        "The Rothschilds",
        "The Bilderberg Group",
        "The New World Order",
    };
    
    // Generate a random index for each array
    int theory_idx = rand() % 5;
    int entity_idx = rand() % 5;
    
    // Print out the conspiracy theory statement
    printf("Did you know? %s is behind %s!\n", entities_involved[entity_idx], conspiracy_theories[theory_idx]);
    
    // Generate a random number of additional related entities to mention
    int num_related_entities = rand() % 4;
    
    // Declare and populate an array of potential related entities
    char* related_entities[] = {
        "The Trilateral Commission",
        "The Club of Rome",
        "The Council on Foreign Relations",
        "The Vatican",
        "The World Health Organization",
        "The Federal Reserve",
        "The United Nations",
        "The Knights Templar",
        "The New Age Movement",
        "The Rosicrucians",
    };
    
    // Keep track of the number of related entities mentioned so far
    int related_entities_count = 0;
    
    // Loop until we've mentioned the desired number of related entities
    while (related_entities_count < num_related_entities) {
        // Generate a random index for the array of related entities
        int related_entity_idx = rand() % 10;
        
        // Make sure we haven't already mentioned this entity and that it's not the same as the main entity involved
        if (related_entities[related_entity_idx] != entities_involved[entity_idx] && related_entities[related_entity_idx] != entities_involved[theory_idx]) {
            printf("In fact, %s is just the tip of the iceberg. %s is also involved, as well as ", related_entities[related_entity_idx]);
            related_entities_count++;
        }
    }
    
    // Finish off the statement
    printf("the lizard people who secretly control the world!\n\n");
    
    // Return 0 to indicate success
    return 0;
}