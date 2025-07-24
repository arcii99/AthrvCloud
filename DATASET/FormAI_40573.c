//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a random conspiracy theory */
char* generate_conspiracy_theory(){
    char* theories[] = {"The moon landing was faked by the government",
                        "The Illuminati controls all world governments",
                        "The COVID-19 vaccine is actually a way to implant microchips in people",
                        "The 9/11 attacks were an inside job",
                        "Tesla's technology was suppressed by the government",
                        "The Earth is actually flat and NASA is lying to us"};
    int num_theories = 6;
    int theory_index = rand() % num_theories;
    return theories[theory_index];
}

int main(){
    /* Seed the random generator */
    srand(time(NULL));
    
    /* Generate and print 10 random conspiracy theories */
    for(int i = 0; i < 10; i++){
        char* theory = generate_conspiracy_theory();
        printf("Conspiracy Theory #%d: %s\n", i+1, theory);
    }
    return 0;
}