//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THEORIES 10

char *theories[NUM_THEORIES] = {
    "The moon is a hologram created by the government.",
    "Aliens exist and are among us.",
    "Climate change is a conspiracy theory created by the government.",
    "The Illuminati is real and controls the world.",
    "The Earth is flat and the government is hiding the truth.",
    "Vaccines cause autism and the government is covering it up.",
    "The CIA killed JFK.",
    "9/11 was an inside job.",
    "Chemtrails are real and the government is using them for mind control.",
    "The government is secretly controlling the weather."
};

void print_theory(char* theory) {
    printf("%s\n\n", theory);
}

void generate_theory() {
    srand(time(NULL));
    int random_theory = rand() % NUM_THEORIES;
    print_theory(theories[random_theory]);
}

int main() {
    generate_theory();
    return 0;
}