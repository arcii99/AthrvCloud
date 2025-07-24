//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *adjectives[] = {"sinister", "secretive", "dangerous", "corrupt", "power-hungry", "scheming"};
    char *nouns[] = {"Illuminati", "New World Order", "Freemasons", "Reptilian overlords", "Deep state", "Shadow government"};
    char *verbs[] = {" manipulating", "brainwashing", "controlling", "maneuvering", "influencing", "grooming"};
    char *objects[] = {"the media", "the government", "the economy", "world events", "society"};

    srand(time(NULL)); //Seed the random generator with the current time

    printf("\n\n\t***Welcome to the Conspiracy Theory Generator***\n\n");

    while(1) {
        printf("Press Enter to generate a new random conspiracy theory. Type 'exit' to quit.\n");
        char input[80];
        fgets(input, 80, stdin);

        if(input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            printf("\nExiting program...\n");
            break;
        }

        printf("\n\n\t**Breaking News!**\n\n");
        printf("We have just uncovered a %s %s %s on %s.\n\n", adjectives[rand()%6], nouns[rand()%6], verbs[rand()%6], objects[rand()%5]);
        printf("This %s is attempting to take over the world through their %s tactics and %s of %s.\n\n", nouns[rand()%6], adjectives[rand()%6], verbs[rand()%6], objects[rand()%5]);
        printf("Stay tuned for more updates as we continue to investigate the %s!\n\n", nouns[rand()%6]);
    }

    return 0;
}