//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *adjective[] = {"government-controlled", "secret", "sinister", "unexplainable", "mysterious", "shadowy", "malevolent", "domineering", "power-hungry", "paranormal"};
    char *noun[] = {"Illuminati", "Big Pharma", "Deep State", "Bilderberg Group", "New World Order", "Reptilian Elite", "Alien Overlords", "Masonic Brotherhood", "Globalists", "Black Ops"};
    char *verb[] = {"manipulates", "brainwashes", "controls", "influences", "subjugates", "corrupts", "dominates", "steals", "assassinates", "conspires against"};
    char *object[] = {"the media", "the masses", "the government", "the economy", "the weather", "historical events", "the stock market", "our minds", "natural disasters", "NASA"};

    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator 3000!\n");

    while (1) {
        printf("\nPress enter to generate a new conspiracy theory or type EXIT to quit:");
        char input[10];
        fgets(input, 10, stdin);
        
        if (input[0] == 'E' || input[0] == 'e') {
            break;
        }
        
        int adj_index = rand() % 10;
        int noun_index = rand() % 10;
        int verb_index = rand() % 10;
        int obj_index = rand() % 10;

        printf("\n%s %s %s %s!", adjective[adj_index], noun[noun_index], verb[verb_index], object[obj_index]);
    }

    printf("\nThanks for using the Random Conspiracy Theory Generator 3000!");

    return 0;
}