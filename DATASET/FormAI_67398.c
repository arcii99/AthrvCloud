//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    
    char* subjects[] = {"The government", "The Illuminati", "The reptilians", "The aliens"};
    char* verbs[] = {"is hiding", "controls", "created", "manipulates"};
    char* nouns[] = {"the truth", "our thoughts", "the weather", "the economy"};
    char* adjectives[] = {"dangerous", "mind-controlling", "secretive", "manipulative"};
    
    int num_sentences = rand() % 20 + 10; // Generates random number of sentences between 10 and 30
    
    for (int i = 0; i < num_sentences; i++) {
        
        int subject_index = rand() % 4;
        int verb_index = rand() % 4;
        int noun_index = rand() % 4;
        int adjective_index = rand() % 4;
        
        printf("%s %s %s with their %s agenda.\n", subjects[subject_index], verbs[verb_index], nouns[noun_index], adjectives[adjective_index]);
    }
    
    printf("\n");
    
    return 0;
}