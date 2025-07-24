//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void conspiracyTheory(int numPlayers) {
    const char* theories[10] = {
        "The moon landing was faked by the US government",
        "The Illuminati control the world's governments",
        "COVID-19 was created in a Chinese lab as a biological weapon",
        "9/11 was an inside job orchestrated by the US government",
        "The government has been hiding evidence of extraterrestrial life for years",
        "Chemtrails are being used by the government to control the population",
        "The pharmaceutical industry is hiding a cure for cancer",
        "The CIA has its own private army that carries out covert operations",
        "The global elite are planning a New World Order",
        "The Titanic was sunk on purpose for financial gain"
    };
    
    srand(time(NULL));
    int selectedTheory = rand() % 10;
    
    printf("Player %d: %s\n", numPlayers, theories[selectedTheory]);
}

int main() {
    int numPlayers;
    printf("How many players are in the game? ");
    scanf("%d", &numPlayers);
    
    printf("\nGenerating random conspiracy theories...\n\n");
    
    for (int i = 1; i <= numPlayers; i++) {
        conspiracyTheory(i);
    }
    
    return 0;
}