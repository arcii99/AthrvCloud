//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    double invasion_prob = (double) rand() / (double) RAND_MAX;
    char* greetings[10] = {"Greetings, earthling!", "Hello, human!", "Salutations, mortal!", "Hey there, meatbag!",
                           "Greetings, fleshling!", "What's up, biped?", "Hey, you with the opposable thumbs!",
                           "Hello, carbon-based life form!", "What do you want?", "What's crackin', human?"};
    char* reactions[10] = {"Your civilization has a 99.999% chance of succumbing to our superior technology.",
                           "Resistance is futile. Your planet will be assimilated.",
                           "We have studied your kind. You cannot defeat us.",
                           "Your scientists were foolish to send a rover to our planet. It was like sending a chicken to a lion.",
                           "We have been monitoring your communications. Your world is doomed.",
                           "You think you have weapons that can stop us? Your primitive devices amuse us.",
                           "Your world will serve as a nice colony for our species.",
                           "We have already infiltrated your governments. You are powerless.",
                           "Your species is better suited for labor and experimentation. We will make good use of you.",
                           "Our arrival was foretold in your ancient texts. The end of your civilization has come."};
    int x = rand() % 10;
    int y = rand() % 10;
    printf("%s\n\n", greetings[x]);
    printf("According to our calculations, the probability of us invading your planet is %f.\n", invasion_prob);
    printf("%s\n", reactions[y]);
    return 0;
}