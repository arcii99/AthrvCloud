//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    int i, j, k, l, m, n, o, p, q, r;
    char* noun[] = {"Illuminati", "government", "aliens", "zombies", "robots", "vampires", "unicorns", "dragons", "sasquatch", "Atlantis", "Bermuda Triangle"};
    char* verb[] = {"controls", "created", "is hiding", "is working with", "is planning to take over", "is brainwashing", "is infiltrating", "is behind"};
    char* adjective[] = {"secret", "hidden", "undiscovered", "sinister", "malevolent", "deceptive", "manipulative", "evil", "terrifying", "mysterious"};
    char* event[] = {"9/11", "JFK assassination", "moon landing", "Roswell incident", "COVID-19 pandemic", "Area 51", "chemtrails", "flat Earth", "Holocaust", "New World Order"};
    char* location[] = {"Antarctica", "Mars", "the moon", "the Vatican", "a secret underground bunker", "the Bermuda Triangle", "Atlantis", "Area 51", "the North Pole", "the South Pole"};
    char* evidence[] = {"a leaked document", "anonymous source", "a whistleblower", "a code hidden in a movie", "a censored book", "broken encryption", "a hidden file", "a deleted email", "a UFO sighting"};

    char response[50];
    while (1) {
        printf("\nDo you want to hear a new conspiracy theory? (y/n)\n");
        scanf("%s", response);
        if (response[0] == 'n' || response[0] == 'N') break;

        i = rand() % 10; // random noun
        j = rand() % 8; // random verb
        k = rand() % 10; // random adjective
        l = rand() % 10; // random event
        m = rand() % 10; // random location
        n = rand() % 9; // random evidence
        o = rand() % 10; // random noun
        p = rand() % 8; // random verb
        q = rand() % 10; // random adjective
        r = rand() % 10; // random event

        printf("\n");
        printf("Conspiracy Theory %d:\n", (rand() % 100) + 1);
        printf("The %s %s %s the %s because of %s in %s.\n", noun[i], verb[j], adjective[k], event[l], evidence[n], location[m]);
        printf("But what they didn't know is that the %s also %s the %s to %s the world with %s!\n", noun[i], verb[p], noun[o], verb[j], event[r]);
    }

    printf("\nThank you for using the Random Conspiracy Theory Generator! Stay safe and be aware of your surroundings.\n");
    return 0;
}