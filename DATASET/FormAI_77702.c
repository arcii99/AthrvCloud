//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* conspiracy_theories[] = {
    "The moon landing was faked",
    "9/11 was an inside job",
    "The government is hiding evidence of aliens",
    "Bigfoot is a government experiment gone wrong",
    "Chemtrails are being used to control the population"
};

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    printf("Welcome to the Random Conspiracy Theory Generator:\n\n");
    
    // generate 5 random conspiracy theories
    for(int i = 0; i < 5; i++) {
        int index = rand() % 5;
        printf("%d. %s\n", i+1, conspiracy_theories[index]);
    }
    
    return 0;
}