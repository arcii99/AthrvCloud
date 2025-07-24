//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void planetTravel(int planet);
void dialog(char* name1, char* name2, char* line1, char* line2);
void loveStory(char* name1, char* name2);

// global variables
char* planets[] = {"Mars", "Venus", "Jupiter", "Saturn", "Mercury", "Neptune", "Uranus", "Pluto"};
int planetsCount = sizeof(planets) / sizeof(planets[0]);

int main() {
    srand(time(NULL));
    int planet = rand() % planetsCount;
    planetTravel(planet);
    loveStory("Romeo", "Juliet");
    return 0;
}

void planetTravel(int planet) {
    printf("Welcome to %s!\n", planets[planet]);
}

void dialog(char* name1, char* name2, char* line1, char* line2) {
    printf("%s: %s\n%s: %s\n", name1, line1, name2, line2);
}

void loveStory(char* name1, char* name2) {
    dialog(name1, name2, "What light through yonder window breaks?", "It is the east, and Juliet is the sun.");
    dialog(name1, name2, "Arise, fair sun, and kill the envious moon,", "Who is already sick and pale with grief,");
    dialog(name2, name1, "O Romeo, Romeo! Wherefore art thou Romeo?", "Deny thy father and refuse thy name;");
    dialog(name1, name2, "Call me but love, and I'll be new baptized;", "Henceforth I never will be Romeo.");
    printf("And thus, Romeo and Juliet lived happily ever after in the vastness of space.\n");
}