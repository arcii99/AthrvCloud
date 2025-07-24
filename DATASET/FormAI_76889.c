//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* adjectives[] = { "sinister", "shadowy", "corrupt", "deviant", "perverse" };
char* organizations[] = { "Illuminati", "Bilderberg Group", "New World Order", "Freemasons" };
char* goals[] = { "world domination", "mass mind control", "economic collapse", "depopulation" };

#define ADJ_LEN (sizeof(adjectives) / sizeof(adjectives[0]))
#define ORG_LEN (sizeof(organizations) / sizeof(organizations[0]))
#define GOAL_LEN (sizeof(goals) / sizeof(goals[0]))

char* generate_conspiracy() {
    srand(time(NULL));
    char* adj = adjectives[rand() % ADJ_LEN];
    char* org = organizations[rand() % ORG_LEN];
    char* goal = goals[rand() % GOAL_LEN];

    char* conspiracy = (char*) malloc(100 + strlen(adj) + strlen(org) + strlen(goal));
    sprintf(conspiracy, "The %s %s is planning %s.", adj, org, goal);

    return conspiracy;
}

int main() {
    printf("%s\n", generate_conspiracy());
}